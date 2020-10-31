#include<bits/stdc++.h>
using namespace std;

void read(char *infile,int *arr[3000],unsigned char header[54],unsigned char colortable[1024])
{
	int i,j;
	FILE *in=fopen(infile,"rb");

	if(in==NULL)
	{
		printf("\n %s doesn't exist !!!\n",infile);
		return;
	}

	fread(header,sizeof(unsigned char),54,in);

	//reading the width,height and bitdepth of data
	int width=*(int *)&header[18];
	int height=*(int *)&header[22];
	int bitdepth=*(int *)&header[28];

	//calculating the size
	int size=width*height*3;
    
    /*if(bitdepth <= 8)
        {fread(colortable, sizeof(unsigned char), 1024, in);
         
        }*/

    printf("width: %d\n",width);
    printf("height: %d\n",height );
    printf("size: %d\n",size );
    printf("bit count: %d\n",bitdepth );

    int padding = 0;

    //padding the data so that it becomes multiple of 4
    while ((width * 3 + padding) % 4 != 0)
        padding++;
   
    int widthnew = width * 3 + padding;
    unsigned char* data = (unsigned char *)malloc(widthnew * sizeof (unsigned int));

    //reading and storing the image data in a 2D array.
    for (i = 0; i<height; i++)
    {

        fread(data, sizeof(unsigned char), widthnew, in);

        for ( j = 0; j < width * 3; j += 3)
        {

            arr[i][j]= (int)data[j] ;
            arr[i][j+1]= (int)data[j+1];
            arr[i][j+2]= (int)data[j+2];
        }
    }


   fclose(in);
}
void write(char *outfile ,int *arr[1500] ,unsigned char header[54],unsigned char colortable[1024])
{
    int i,j;
      FILE *out = fopen(outfile,"wb");
    int  width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int  bitDepth  = *(int*)&header[28];

    fwrite(header, sizeof(unsigned char), 54, out);
     /*if(bitDepth <= 8)
        {
         fwrite(colortable, sizeof(unsigned char), 1024, out);
        }*/
     int padding = 0;

    while ((width * 3 + padding) % 4 != 0)
        padding++;

    int widthnew = width * 3 + padding;
    
      unsigned char* data = (unsigned char *)malloc(widthnew * sizeof (unsigned int));

     for ( i = 0; i<height; i++)
    {
        for ( j = 0; j < widthnew; j += 3)
        {
            
            data[j] = arr[i][j] ;
            data[j+1] = arr[i][j+1];
            data[j+2] = arr[i][j+2];
        }
      
        fwrite(data, sizeof(unsigned char), widthnew, out);
    }
    fclose(out);
}
void medianfilter( int height ,int width, int *arr[3000])
 {  
 	int med[30];
    for (int i = 0; i<height; i++)
    
      for(int j=0 ; j<width ; j++)
       {  
           int c=0;
           for(int m=i-2; m<=i+2 ; m++)
            {
               for(int n=j-2; n<=j+2 ; n++)
                 {
                     if(m< 0 || n< 0 || m>=height | n>=width)
                        continue;
                     else
                        {
                        //storing the values
                          med[c]=arr[m][n];
                          c++;
                        } 
                 }
            }
        //sorting the values and finding the median.
         sort(med,med+c);
         arr[i][j]=med[c/2];; 
            
       }

}
void median( int height ,int width, int *arr[3000])
 {  int i,j,m,n,k;
    int *r[height],*g[height],*b[height],in;
    for ( in=0; in<height; in++)
         r[in] = (int *)malloc(width*sizeof(int));
     for ( in=0; in<height; in++)
         g[in] = (int *)malloc(width*sizeof(int));
    for ( in=0; in<height; in++)
         b[in] = (int *)malloc(width*sizeof(int));

     //storing the data in each of the r,g,b array.
    for (int i = 0; i<height; i++)
    
      for(int j=0,k=0 ; j<width*3 ; j+=3,k++)
       {  
          r[i][k]= arr[i][j];
          g[i][k]= arr[i][j+1];
          b[i][k]= arr[i][j+2];
       }

    //finding the medianfilter for each of r,g,b channels.
    medianfilter(height,width,r);
    medianfilter(height,width,g);
    medianfilter(height,width,b);

    //combining the result in a single array.
   for (int  i = 0; i<height; i++)
    
      for(int j=0,k=0 ; j<width*3 ; j+=3,k++)
       {  
          arr[i][j]=r[i][k];
          arr[i][j+1]=g[i][k];
          arr[i][j+2]=b[i][k];
       }

 }
int main(int argv,char *argc[])
{
	int *arr[3000];

	for(int i=0;i<3000;i++)
	{
		arr[i]=(int *)malloc(3000*3*sizeof(int));
		
	}

	unsigned char header[54],colortable[1024];

	//taking input for data
	read(argc[1],arr,header,colortable);

	int width = *(int*)&header[18];
    int height = *(int*)&header[22];	

    //processing
    median(height,width,arr);

    //writting in the output file
    write(argc[2],arr,header,colortable);
}