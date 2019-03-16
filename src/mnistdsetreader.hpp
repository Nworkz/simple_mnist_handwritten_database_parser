//
//  mnistdsetreader.hpp
//  mnist dataset reader
//
//  Created by Neil Immanuel De Guzman on 16/03/2019.
//  Copyright © 2019 Neil Immanuel De Guzman. All rights reserved.
//

#ifndef mnistdsetreader_hpp
#define mnistdsetreader_hpp

#include <fstream>
#include <vector>

namespace mnist {
    
    struct image{
        int *elements;
    };
    
    struct labeledPixelGroup{
        int label;
        image img;
    };
    
    int readNextAsInt(std::fstream &file);
    std::vector<int> readLabels(const std::string &filename);
    std::vector<mnist::image> readImage(const std::string &filename);
    std::vector<labeledPixelGroup>  readBoth(const std::string &labelFilename, const std::string &imageFilename);
}

#endif /* mnistdsetreader_hpp */
