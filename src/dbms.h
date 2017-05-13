#include <stdio.h>
#include<stdlib.h>
#include<string.h>

char lineG [180];
static char * readLine(char * _inputFilePath)
{
 static FILE *file;

     if(file == NULL)
        file = fopen ( _inputFilePath , "r" ); //open file
     if ( file != NULL )
     {
     if( fgets ( lineG, sizeof (lineG), file ) != NULL ) /* read a line */
     return lineG;
     else
     fclose ( file );
     }
     else perror ( "input.txt" ); /* why didn't the file open?*/
     return NULL;
}

struct category {;
    char nameCategory [30];
    struct category *next;
}*start=NULL;
struct product{
    char nameProduct [101];
    float priceProduct;
    struct category *_category;
    struct product *next;
}*startPro=NULL;
struct category *currentCategory , *newCategory , *tempCategory,*searchC;
struct product *currentProduct, *newProduct,*tempProduct,*searchP , *previousProduct, *asdf;
char *line , *temp , *temp2 , *temp3 , *temp4,*nameC,*namePro, *namePri, *isValidCategoryActionName, *isValidPriceActionName ,tempW , *inputFilePath;
float price , tempFloatvalue , number , number2;
int i=0, alreadyDefined = 0, alreadyAdded = 0;
FILE *out_file;

void addCategory( char *_nameCategory )  /* adding to end of list */
{
    newCategory=(struct category *)malloc(sizeof(struct category));
    searchC=start;
    while(searchC !=NULL){
        if((strcmp(searchC->nameCategory,_nameCategory))==0){
            alreadyDefined = 1;
            fprintf(out_file,"Command:\nCREATE CATEGORY NAME \"%s \"\nResult:\nFAILED.\n\n\n",_nameCategory);
            break;
        }
        searchC=searchC->next;
    }
    if(alreadyDefined == 0){
        strcpy(newCategory->nameCategory,_nameCategory);
        newCategory->next=NULL;

        if(start==NULL){
           fprintf(out_file,"Command:\nCREATE CATEGORY NAME \"%s \"\nResult:\nSUCCESSFUL.\n\n\n",_nameCategory);
            start = newCategory;
        }
        else{
            currentCategory->next=newCategory;
            fprintf(out_file,"Command:\nCREATE CATEGORY NAME \"%s \"\nResult:\nSUCCESSFUL.\n\n\n",_nameCategory);
        }
        currentCategory=newCategory;
    }
    else{
        alreadyDefined = 0;
    }
}

void addProduct(char *_nameCategory, char *_nameProduct, char *_Price){
    /* Find Category */
    searchC = start;
    while(searchC !=NULL){
        if((strcmp(searchC->nameCategory,_nameCategory))==0){
            break;
        }
        searchC=searchC->next;
    }
    if(searchC == NULL){
        fprintf(out_file,"Command:\nCREATE PRODUCT NAME \"%s \" CATEGORY \" %s\" PRICE \"%s\" \nResult:\nFAILED.\n\n\n",_nameProduct,_nameCategory,_Price);
    }
    else{
        while(searchP != NULL){
            if(strcmp(searchP->nameProduct,_nameProduct) == 0){
                if(strcmp(searchP->_category->nameCategory, _nameCategory)){
                    alreadyAdded = 1;
                }
            }
        }
        if(alreadyAdded == 1){
            fprintf(out_file,"Command:\nCREATE PRODUCT NAME \"%s \" CATEGORY \" %s\" PRICE \"%s\" \nResult:\nFAILED.\n\n\n",_nameProduct,_nameCategory,_Price);
        }
        else{
            /* Create an empty node */
            newProduct=(struct product *)malloc(sizeof(struct product));
            /* Insert Values */
            strcpy(newProduct->nameProduct, _nameProduct);
            newProduct->priceProduct =  atof(_Price);
            newProduct->_category = searchC;
            newProduct->next = NULL;

            if(startPro == NULL){
                fprintf(out_file,"Command:\nCREATE PRODUCT NAME \"%s \" CATEGORY \" %s\" PRICE \"%s\" \nResult:\nSUCCESFUL..\n\n\n",_nameProduct,_nameCategory,_Price);
                startPro = newProduct;
            }
            else{
                fprintf(out_file,"Command:\nCREATE PRODUCT NAME \"%s \" CATEGORY \" %s\" PRICE \"%s\" \nResult:\nSUCCESFUL.\n\n\n",_nameProduct,_nameCategory,_Price);
                currentProduct->next = newProduct;
            }
            currentProduct = newProduct;
        }
        alreadyAdded = 0;
    }
}

void listCategoryAll () {
    fprintf(out_file,"Command:\nLIST CATEGORY ALL\n");
    searchC = start;
    while(searchC != NULL){
        fprintf(out_file,"Result:\nCATEGORY NAME \"%s\"\n", searchC->nameCategory);
        searchC = searchC->next;
    }
}

void listProductAll(){
    fprintf(out_file,"\nCommand:\nLIST PRODUCT ALL\nResult:\n");
    searchP = startPro;
    while(searchP != NULL){
        searchC = searchP->_category;
        fprintf(out_file,"PRODUCT NAME \"%s\" CATEGORY \"%s\" PRICE \"%f\"\n" ,
                        searchP->nameProduct,
                        searchC ->nameCategory,
                        searchP->priceProduct);
        searchP = searchP->next;
    }
}

void listProductWhereNameIs(char * _nameProduct){
    searchP=startPro;
    while(searchP != NULL){
        searchC = searchP->_category;
        if(strcmp(searchP->nameProduct,_nameProduct)==0){
            fprintf(out_file,"Command:\n LIST PRODUCT WHERE NAME IS \"%s\"\nResult:\nPRODUCT NAME \"%s\" CATEGORY \"%s\" PRICE \"%f\"\n\n\n",
                    _nameProduct,
                    searchP->nameProduct,
                    searchC ->nameCategory,
                    searchP->priceProduct);
            break;
        }
        searchP=searchP->next;
    }
}

void listProductWherePriceIs(char *_nameProduct){
    searchP=startPro;
    tempFloatvalue = atof(_nameProduct);
    while(searchP != NULL){
        searchC = searchP->_category;
        if(searchP->priceProduct == tempFloatvalue){
            fprintf(out_file,"Command:\n LIST PRODUCT WHERE PRICE IS \"%s\"\nResult:\nPRODUCT NAME \"%s\" CATEGORY \"%s\" PRICE \"%f\"\n\n\n",
                    _nameProduct,
                    searchP->nameProduct,
                    searchC ->nameCategory,
                    searchP->priceProduct);
            break;
        }
        searchP=searchP->next;
    }
}

void listProductWhereCategoryIs(char *_nameProduct){
    searchP=startPro;
    fprintf(out_file, "Command:\n LIST PRODUCT WHERE CATEGORY IS \"%s\"\nResult:\n",_nameProduct);
    while(searchP != NULL){
        searchC = searchP->_category;
        if(strcmp(searchP->_category->nameCategory,_nameProduct)==0){
            searchC = searchP->_category;
            fprintf(out_file,"PRODUCT NAME \"%s\" CATEGORY \"%s\" PRICE \"%f\"\n" ,

                            searchP->nameProduct,
                            searchC ->nameCategory,
                            searchP->priceProduct);
        }
        searchP = searchP->next;
    }
}

void listProductWhereBetweenIs(float _number , float _number2){
    searchP=startPro;
    fprintf(out_file,"Command:\n LIST PRODUCT WHERE BETWEEN IS %f %f\nResult:\n",
                    _number,
                    _number2);
    while(searchP != NULL){
        searchC = searchP->_category;
        if(searchP->priceProduct >= _number && searchP->priceProduct <= _number2){
            fprintf(out_file,"PRODUCT NAME \"%s\" CATEGORY \"%s\" PRICE \"%f\"\n",

                    searchP->nameProduct,
                    searchC ->nameCategory,
                    searchP->priceProduct);
        }
        searchP = searchP->next;
    }
}

void createImage(){
     searchC = start;
    while(searchC != NULL){
        fprintf(out_file,"CATEGORY NAME \"%s\"\n", searchC->nameCategory);
        searchC = searchC->next;
    }
    searchP = startPro;
    while(searchP != NULL){
        searchC = searchP->_category;
        fprintf(out_file,"PRODUCT NAME \"%s\" CATEGORY \"%s\" PRICE \"%f\"\n" ,
                        searchP->nameProduct,
                        searchC ->nameCategory,
                        searchP->priceProduct);
        searchP = searchP->next;
    }
}

void deleteProduct (char _nameCategory , char _nameProduct){
     while(searchC !=NULL){
        if((strcmp(searchC->nameCategory,nameC))==0){
            searchP=startPro;
            while(searchP != NULL){
                if(strcmp(searchP->nameProduct,temp)==0){
                    tempProduct = searchP;
                    searchP = searchP->next;
                    free(tempProduct);
                fprintf(out_file,"Command:\nDELETE PRODUCT WHERE NAME IS \"%s\" AND CATEGORY IS \"%s\"\nResult:\nSUCCESFUL"
                       ,temp,nameC);
                }
                searchP=searchP->next;
            }
            break;
        }
        searchC=searchC->next;
    }
}

void sortProduct(){
    searchP = startPro;
    //searchP = startPro->next;

    while(searchP != NULL){
        if(searchP->next == NULL){
            break;
        }
        tempProduct = searchP->next;

        if(searchP->priceProduct >= tempProduct->priceProduct){
            if(previousProduct != NULL){
                    printf("%f -- %f", searchP->priceProduct, tempProduct->priceProduct);
                asdf = tempProduct->next;
                searchP->next = asdf;
                previousProduct->next = tempProduct;
                tempProduct->next = searchP;
            }
        }
        previousProduct = searchP;

        searchP = searchP->next;
    }
}

void sorting(struct product * _Product){
    if(_Product->next == NULL){
            printf("null\n");
        return;
    }
    if(_Product->priceProduct > _Product->next->priceProduct){
        swapProduct(_Product, _Product->next);
        sorting(_Product->next);
    }
}

void swapProduct(struct product *first, struct product *second){
    searchP = startPro;
    while(searchP != NULL){
        if(searchP->next == first->next){
            break;
        }
        previousProduct = searchP;
        searchP = searchP->next;
    }

printf("sirala2\n");
    asdf = second->next;
    first->next = asdf;
    previousProduct->next = second;
    second->next = first;
}
