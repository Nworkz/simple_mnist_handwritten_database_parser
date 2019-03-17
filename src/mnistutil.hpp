//
//  mnistutil.hpp
//  mnist dataset reader
//
//  Created by Neil Immanuel De Guzman on 16/03/2019.
//  Copyright © 2019 Neil Immanuel De Guzman. All rights reserved.
//

#ifndef mnistutil_hpp
#define mnistutil_hpp

#include "mnistdsetreader.hpp"
#include "mnistdsetreader.hpp"

namespace mnist{
    void binarize(mnist::image &image, int dim);
    mnist::imageF floatScale(mnist::image image, int dim);
}
#endif