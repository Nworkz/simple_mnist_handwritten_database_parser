//
//  main.cpp
//  mnist dataset reader
//
//  Created by Neil Immanuel De Guzman on 15/03/2019.
//  Copyright © 2019 Neil Immanuel De Guzman. All rights reserved.
//

#include <iostream>
#include "src/mnistdsetreader.hpp"
#include "src/mnistutil.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::vector<int> labels = mnist::readLabels("./dataset/train-labels.idx1-ubyte");
    std::vector<mnist::image> images = mnist::readImage("./dataset/train-images-idx3-ubyte");
    
    //std::vector<mnist::labeledPixelGroup> lpgs = mnist::readBoth("./dataset/train-labels.idx1-ubyte", "./dataset/train-images.idx3-ubyte");

    mnist::imageF imagef = mnist::floatScale(images[3000], 28*28);

    for(int x = 0; x < 28*28; x++){
        if(imagef.elements[x] != 0){
            std::cout << "@";
        }else{
            std::cout << "-";
        }
        
        if(x % 28 == 0){
            std::cout << std::endl;
        }
    }
    return 0;
}
