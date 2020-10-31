# Problem statement 1 :
Implement a median filter from scratch using C++. Input should be an Image and the output should be a reduced noisy image.

  Objective:
   * To remove noise from an image using median filter algorithm using c++ and output the resultant image.
  
  Procedure:
   * There are four different function each of whose purpose is described below in chronological order.
  
  1)Read fucntion:
  * It takes input file name,array to store the data from input file and header array to store the header information of the image.
  * It reads the header and stores width,height and bitdepth of the image.
  * It aslo padds the data.
  * And finally it stores the data in a 2D array.
    
   2)median function:
   * It first stores the data from three different channels(i.e, r g b) to three different array.
   * It then calls the medianfilter function and finds the median of each channel seperately
   * Then again stores all the data again in a single 2D array after proccessing.
   
   3)medianfilter function:
   * finds median of the pixel value stored in array by taking 25 pixel values around a single pixel.
   * It sorts the values and finds the mid value and stores in the place of the pixel value around wich it is calculated.
   
   4)Write function:
   * It is same as input fucntion.In place of input file it takes an output file and stores the resultant image pixel values obtained from above functions

  Obseravtion:
  * It reduces the noise of the image.
  * It takes O(n*m) time comlpexity where n and m are height and width of the image.
   


# Problem statement 2 :
#File crawler

 Ojective:
  * To crawl through a number of text files and find number of times a given word has appeared in those text files.
 
 Structure of file crawler:
  * It is a class
  * It consist of a vector for storing all the file paths
  * And another vector which stores each word in a particular file according to there index.
  * It consists of methods crawling,search and stroringfile.
 
 Procedure:
  * First it stores the paths of the files using storing file method
  * Then for each file path it opens the file and read it and stores it words using crawling function. 
  * finally for a particular word given by user, it searches from the vector using search function that has stored the words and gives count for each of number of     times that word has appeared in a particular file  .
