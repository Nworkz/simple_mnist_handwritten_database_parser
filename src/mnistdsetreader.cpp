//
//  mnistdsetreader.cpp
//  mnist dataset reader
//
//  Created by Neil Immanuel De Guzman on 16/03/2019.
//  Copyright © 2019 Neil Immanuel De Guzman. All rights reserved.
//

#include "mnistdsetreader.hpp"
#include <iostream>

#define IMAGE_KEY 0x00000803
#define LABEL_KEY 0x00000801

std::vector<mnist::labeledPixelGroup> mnist::readBoth(const std::string &labelFilename, const std::string &imageFilename){
    std::fstream labelFile(labelFilename,std::ios::in|std::ios::binary);
    std::fstream imageFile(imageFilename,std::ios::in|std::ios::binary);
    
    std::vector<mnist::labeledPixelGroup> lpgs;
    
    if(labelFile.is_open() && imageFile.is_open()){
        if(readNextAsInt(labelFile) == LABEL_KEY && readNextAsInt(imageFile) == IMAGE_KEY){
            //read for label
            int lFSize = readNextAsInt(labelFile);
            //read for image
            int imgFSize = readNextAsInt(imageFile);
            int w = readNextAsInt(imageFile);
            int h = readNextAsInt(imageFile);
            
            if(lFSize == imgFSize){
                char *lblBuffer = new char[lFSize];
                labelFile.read(lblBuffer, lFSize);
                
                //continue here
                for(int i = 0; i < lFSize; i++){
                    mnist::labeledPixelGroup lpg;
                    lpg.label = (int)*lblBuffer++;
                    lpg.img.elements = new int[w*h];
                    
                    char *pixelBuffer = new char[w*h];
                    imageFile.read(pixelBuffer, w*h);
                    
                    for(int j = 0; j < w * h;j++){
                        lpg.img.elements[j] = *pixelBuffer++;
                    }
                    
                    lpgs.push_back(lpg);
                }
            }else{
                std::cout << "Number of elements do not match";
            }
        }else{
            std::cout << "file key does not match";
        }
    }else{
        std::cout << "can't open one of the files";
    }
    
    return lpgs;
}

std::vector<mnist::image> mnist::readImage(const std::string &filename){
    std::fstream file(filename,std::ios::in|std::ios::binary);
    std::vector<mnist::image> images;
    
    if(file.is_open()){
        if(readNextAsInt(file) == IMAGE_KEY){
            int size = readNextAsInt(file);
            int w = readNextAsInt(file);
            int h = readNextAsInt(file);
            
            //this thing is really ugly; just make this work for now
            //and make this thing beautifl later
            for(int i = 0; i < size; i++){
                mnist::image image;
                image.elements = new int[w*h];
                
                //this might be dangerous
                char *buffer = new char[w*h];
                file.read(buffer,w*h);

                for(int j = 0; j < w * h;j++){
                    image.elements[j] = *buffer++;
                }
                
                images.push_back(image);
            }
        }else{
            std::cout << "wrong file key";//change this to throw later
        }
    }else{
        std::cout << "can't open " << filename;//change this to throw later
    }
    
    return images;
}

std::vector<int> mnist::readLabels(const std::string &filename){
    std::fstream file(filename,std::ios::in|std::ios::binary);
    
    std::vector<int> labels = std::vector<int>();
    
    if(file.is_open()){
        if(readNextAsInt(file) == LABEL_KEY){
            int size = readNextAsInt(file);
            
            char *buffer = new char[size];
            file.read(buffer,size);
            
            //I really don't know if this is a good idea; but it works
            for(int i = 0; i < size; ++i){
                //*labels++ = (int)*buffer++;
                labels.push_back(*buffer++);
            }
            
        }else{
            std::cout << "wrong file key";//change this to throw later
        }
    }else{
        std::cout << "can't open " << filename;//change this to throw later
    }
    
    return labels;
}


int readNextAsInt(std::fstream &file){
    uint32_t ret;
    file.read(reinterpret_cast<char*>(&ret), 4);
    ret = ((ret << 8) & 0xFF00FF00) | ((ret >> 8) & 0xFF00FF);
    
    return (ret << 16 | ret >> 16);
}
