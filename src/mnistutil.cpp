//
//  mnistutil.cpp
//  mnist dataset reader
//
//  Created by Neil Immanuel De Guzman on 16/03/2019.
//  Copyright © 2019 Neil Immanuel De Guzman. All rights reserved.
//

#include "mnistutil.hpp"

void mnist::binarize(mnist::image &image, int dim){
    for(int x = 0; x < dim; x++){
        if(image.elements[x] != 0){
            image.elements[x] = 1;
        }
    }
}

mnist::imageF mnist::floatScale(mnist::image image, int dim){
    mnist::imageF imagef;
    imagef.elements = new float[dim];

    float max = 255;
    float min = 0;

    for(int x = 0; x < dim; x++){
       imagef.elements[x] = (image.elements[x] - min) / (max - min);
    }

    return imagef;
}