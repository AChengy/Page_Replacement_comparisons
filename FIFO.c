//
// Created by Alex on 12/6/2015.
//

#include <stdio.h>
#include "FIFO.h"

int FIFO(int nframes, int npages, int *pages) {
    int i, j, n, frame[10], no, k, avail, count = 0;
    n=npages;
    no= nframes;

    //populate the frame array with -1 for the frames in use
    for (i = 0; i < no; i++)
        frame[i] = -1;
    j = 0;

    //Loop through the pages
    for (i = 1; i <= n; i++) {
      //set the flag to zero
        avail = 0;
        //look through the page frames to see if it is available
        for (k = 0; k < no; k++)
            //if available set the flag = 1
            if (frame[k] == pages[i])
                avail = 1;
                //else the page faults 
        if (avail == 0) {
            frame[j] = pages[i];
            j = (j + 1) % no;
            count++;
        }
    }
    return count;
}
