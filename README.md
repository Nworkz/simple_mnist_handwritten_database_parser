# simple_mnist_handwritten_database_parser//

readImage, readLabels, and readBoth are located inside the mnist namespace

# Sample

# if you want images only

```c++
std::vector<mnist::image> images = mnist::readImage("./dataset/train-images.idx3-ubyte");
```

# sample of accesing the pixels

```c++

    //this access the 2nd element of the 60000 images
    //change the images[x] to lpgs[x].image.elements[x] if you want to use the readboth
    for(int x = 0; x < 28 * 28; x++){
        if(images[1].elements[x] >= 0){
            std::cout << "@";
        }else{
            std::cout << "#";
        }
        
        if(x % 28 == 0){
            std::cout << std::endl;
        }
    }
    
```

# if you want labels only

```c++

std::vector<int> labels = mnist::readLabels("./dataset/train-labels.idx1-ubyte");

```
  
# if you want to read both

```c++

std::vector<mnist::labeledPixelGroup> lpgs = mnist::readBoth("./dataset/train-labels.idx1-ubyte", "./dataset/train-images.idx3-ubyte")

```



