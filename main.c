//
// Created by Alex on 12/6/2015.
//

#include "main.h"

int main()
{
    int number_of_frames;
    int number_of_pages;
    int temp;
    printf("Enter no. of frames (up to 10):\n");
    scanf("%d",&number_of_frames);

    printf("Enter no. of pages:\n");
    scanf("%d",&number_of_pages);

    //create array to hold pages
    int pages[number_of_pages];

    printf("Enter the %d pages\n",number_of_pages);
    //populate array
    for(int i=0;i<number_of_pages;i++){
        scanf("%d",&temp);
        pages[i]=temp;
    }

    //call the LRU algorithm
    int lrupf = LRU(number_of_frames,number_of_pages,pages);
    printf("LRU number of page faults: %d\n",lrupf);
    //call the FIFO algorithm
    int fifopf = FIFO(number_of_frames,number_of_pages,pages);
    printf("Fifo number of page faults: %d\n",fifopf);


    return 0;
}//end main
