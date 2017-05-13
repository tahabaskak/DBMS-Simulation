#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "deneme.h"

int main (int argc , char *argv[]){
    //inputFilePath=argv[1];
    out_file = fopen(argv[2], "w+");
    if (out_file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }else{
        for(i=0; i<5000; i++){

        line = readLine(argv[1]);
        if(line != NULL){
            temp=strtok(line," ");
            if(strcmp("CREATE",temp)==0){  //Adding and creat image
                temp=strtok(NULL," ");
                if(strcmp("CATEGORY",temp)==0){   // Category adding
                    temp=strtok(NULL," ");
                    if(strcmp("NAME",temp)==0){
                        nameC = strtok(NULL,"\"");
                        addCategory(nameC);
                    }
                }
                else if(strcmp("PRODUCT",temp)==0){  // Adding product
                    temp=strtok(NULL," ");
                    if(strcmp("NAME",temp)==0){  // Name adding for product
                        namePro = strtok(NULL,"\"");
                        isValidCategoryActionName = strtok(NULL, " ");
                        if(strcmp(isValidCategoryActionName, "CATEGORY") == 0){ // Category Adding for Product
                            nameC = strtok(NULL, "\"");
                            isValidPriceActionName = strtok(NULL, " ");
                            if(strcmp(isValidPriceActionName, "PRICE") == 0){  // Price Adding for Product
                                namePri = strtok(NULL, " ");
                                addProduct(nameC, namePro, namePri);
                            }
                            else{               //WRONG ACTION NAME FOR CREATE OF PRODUCT [PRICE]
                               fprintf(out_file,"Command:\nCREATE PRODUCT NAME \"%s \" CATEGORY \" %s\" PRICE \" %s\"\nResult:\nFAILED.\n\n\n",namePro,nameC,namePri);
                            }
                        }
                        else{               //WRONG ACTION NAME FOR CREATE OF PRODUCT [CATEGORY]
                            fprintf(out_file,"Command:\nCREATE PRODUCT NAME \"%s \" CATEGORY \" %s\" PRICE \" %s\"\nResult:\nFAILED.\n\n\n",namePro,nameC,namePri);
                        }
                    }
                }
                else if(strcmp("IMAGE\n",temp)==0){
                    fprintf(out_file,"Command:\nCREATE IMAGE\nResult:");
                    createImage();
                    fprintf(out_file,"\n\n\n");
                }
            }
            else if (strcmp("LIST",temp)==0){  // Listing
                temp = strtok(NULL," ");
                if(strcmp("CATEGORY", temp) == 0){ //List category all
                    temp = strtok(NULL, " ");
                    if(strcmp("ALL\n", temp) == 0){
                        listCategoryAll();   // List it that all Category
                    }
                    else{
                        fprintf(out_file,"Result:\nFAILED.\n");//WRONG COMMAND [LIST CATEGORY]\n
                    }
                }
                else if(strcmp("PRODUCT", temp) == 0){ // listing product...
                        temp = strtok(NULL," ");
                        if(strcmp("WHERE", temp) == 0){
                            temp = strtok(NULL," ");
                             if(strcmp("PRICE" , temp) == 0){  // List product prýce one number is listing.
                                temp = strtok(NULL, " ");
                               if(strcmp("IS",temp)==0){
                                    fprintf(out_file,temp);
                                    temp = strtok(NULL, " ");
                                    listProductWherePriceIs(temp);
                                }
                                else if(strcmp("BETWEEN",temp)==0){  // List product price between to numbers is listing.
                                    temp = strtok(NULL, " ");
                                    number = atof(temp);
                                    temp2 = strtok(NULL," ");
                                    number2 = atof(temp2);
                                    listProductWhereBetweenIs( number , number2);
                                }
                            }
                           else if(strcmp("CATEGORY",temp)==0){       // List product where category is listing.
                                temp = strtok(NULL, " ");
                                if(strcmp("IS",temp)==0){
                                    temp = strtok(NULL, "\"");
                                    listProductWhereCategoryIs(temp);
                                }
                            }
                           else if(strcmp("NAME" , temp) == 0){  // List product where name is listing.
                                temp = strtok(NULL, " ");
                                if(strcmp("IS",temp)==0){
                                    temp = strtok(NULL,"\"");
                                    listProductWhereNameIs(temp);  // List it that where name is
                                }
                            }

                        }
                        else if(strcmp("ALL\n", temp) == 0){    // list it that all product
                            listProductAll();
                        }

                        else{               //WRONG COMMAND [LIST CATEGORY]\n
                            fprintf(out_file,"Command:\n LIST PRODUCT ALL\nResult:\nPRODUCT NAME \"%s\" CATEGORY \"%s\" PRICE \"%f\"\nResult:\nFAILED.\n\n\n",
                                                searchP->nameProduct,
                                                searchC ->nameCategory,
                                                searchP->priceProduct);
                        }
                }
            }
            else if(strcmp("DELETE",temp)==0){  // Delete product
                temp = strtok(NULL, " ");
                if(strcmp("PRODUCT",temp)==0){
                    temp = strtok(NULL," ");
                    if(strcmp("WHERE",temp)==0){
                        temp=strtok(NULL," ");
                        if(strcmp("NAME",temp)==0){
                            temp = strtok(NULL," ");
                            if(strcmp("IS",temp)==0){
                                temp = strtok(NULL,"\"");
                                temp2 = strtok(NULL," ");
                                temp3 = strtok(NULL," ");
                                temp4 = strtok(NULL," ");
                                nameC = strtok(NULL,"\"");
                                searchC=start;
                               deleteProduct(nameC,temp);
                            }
                        }
                    }
                }
            }
            else if(strcmp("SORT",temp)==0){    // sorting
                temp=strtok(NULL," ");
                if(strcmp("PRODUCT",temp)==0){
                    temp=strtok(NULL," ");
                    if(strcmp("BY",temp)==0){
                        temp=strtok(NULL," ");
                        if(strcmp("PRICE",temp)==0){
                            temp = strtok(NULL," ");
                            if(strcmp("DESC\n",temp)==0){

                            }
                        }
                    }
                }
            }
        }
    }
    }


}

