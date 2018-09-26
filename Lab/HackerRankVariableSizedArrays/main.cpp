/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables and arrays
     const int MAX=50000; //I had to remove a 0 netbeans wouldnt even compile
     const int ROW=300000;//"                                                "
     int a[MAX]={};//1-D Array
     int rc[ROW]={};//1-D Array where each row will start in the 1-D array above
     int n,q,cnt,k;
     //Read in the data
     cin>>n>>q;//#Rows and #Queries
     //Read in the entire array
     cnt=0;//Start the array count at 0
     for(int i=0;i<n;i++){
         cin>>a[i];//read in number of elements per col
         for(int j=0;j<a[i];j++,cnt++){
             cin>>rc[cnt];//read in the elements
         }
     }
     int row;//which col we are getting data from
     int col;//which element we are getting data form
    int pos=-1;//tracker
    //Output data
     for(int i=0;i<q;i++){
         cin>>row>>col;//input row and col
         for(int j=0;j<row;j++){
             pos+=a[j];//skips indexes for however many in col
         }
         if(i==0)pos+=1;//for first cycle
         cout<<rc[pos+col]<<endl;//output data
         pos=0;
     }
    
    //Exit stage right!
    return 0;
}
//Expected Output
// 925358
// 867809
// 867809
// 71140
// 867809
// 925358
// 990104
// 996043
// 916135
// 994309

//Input
// 10 10
// 3 916135 272188 794963
// 3 178997 502468 671251
// 1 122266
// 3 223511 996043 990104
// 3 319694 335208 200789
// 2 867809 273793
// 1 925358
// 1 71140
// 1 862238
// 1 994309
// 6 0
// 5 0
// 5 0
// 7 0
// 5 0
// 6 0
// 3 2
// 3 1
// 0 0
// 9 0