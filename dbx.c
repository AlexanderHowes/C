//Alexander Howes
//820184866 cssc1957
//CS 530 Spring 2020
//Assignment 1. Hex/Bin dump
//dbx.c
#include <stdio.h>  
#include <stdlib.h>
#include <ctype.h> 
int main(int argc, char *argv[]) {
    int flag = 1;
    if(argc == 3){
        flag = 2;
    }
    FILE *file = fopen(argv[flag], "r");  
    fseek(file, 0, SEEK_END);  
    int length = ftell(file);  
    char *data = malloc(length);  
    fseek(file, 0, SEEK_SET);  
    fread(data, 1, length, file);  
    fclose(file);
    if(length == 0){
        printf("%s", "No valid characters in file");
    }
    int i;
    unsigned char ch;
    int j;
    int count = 0;
    int place = 0;
    char cr = '\n';
    if(flag == 1){
        for(i=0; i<=length; i++){
            //printf("%i", i);
            if(i==0){
                printf("%p", &((unsigned char*)data)[0]);
                printf("%s", ": ");
            }
            if(((unsigned char*)data)[i] == 0X00){
                if(count % 2 != 0){
                    printf("%s", "00");
                }
                printf("%s", " :: ");
                for(j=place;j<i;j++){
                    if(isprint(((unsigned char*)data)[j])==0){
                        printf("%s", ".");
                    }
                    else{
                    printf("%c", ((unsigned char*)data)[j]);
                    }
                }
                break;
            }
            if (i != 0 && i % 8 == 0){
                printf("%s", ":: ");
                for(j=place;j<i;j++){
                    if(isprint(((unsigned char*)data)[j])==0){
                        printf("%s", ".");
                    }
                    else{
                    printf("%c", ((unsigned char*)data)[j]);
                    }
                }
                place = i;
                printf("\n%p", &((unsigned char*)data)[i]);
                printf("%s", ": ");
                printf("%02X", ((unsigned char*)data)[i]);
                count = count +1;
            }
            else{
		        printf("%02X", ((unsigned char*)data)[i]);
                count = count +1;
                if(count % 2 == 0){
                    printf("%s", " ");
                }
            }
        }
    }
    if(flag == 2){
        int newl = length*2+1;
        char hexstr[newl];
        i = 0;
        count = 0; 
        while(data[i] != '\0'){
            sprintf((char*)(hexstr+count),"%02X", data[i]);
            i+=1;
            count+=2;
        }
        hexstr[count++] = '\0';
        for(i=0;i<newl;i++){
            if(i == 0){
                printf("\n%p", &hexstr[i]);
                printf("%s", ":");
            }
            if(i != 0 && i % 12 == 0){
                printf("%s", ":: ");
                for(j=place;j<i/2;j++){
                     if(isprint(((unsigned char*)data)[j])==0){
                        printf("%s", ".");
                    }
                    else{
                    printf("%c", data[j]);
                    }
                place = i/2;
                }
                printf("\n%p", &hexstr[i]);
                printf("%s", ":");
            }
            if(i%2 == 0){
                    printf("%s", " ");
                }
            if(hexstr[i] == '0'){
                printf("%s", "0000");}
            if(hexstr[i] == '1'){
                printf("%s", "0001");}
            if(hexstr[i] == '2'){
                printf("%s", "0010");}
            if(hexstr[i] == '3'){
                printf("%s", "0011");}
            if(hexstr[i] == '4'){
                printf("%s", "0100");}
            if(hexstr[i] == '5'){
                printf("%s", "0101");}
            if(hexstr[i] == '6'){
                printf("%s", "0110");}
            if(hexstr[i] == '7'){
                printf("%s", "0111");}
            if(hexstr[i] == '8'){
                printf("%s", "1000");}
            if(hexstr[i] == '9'){
                printf("%s", "1001");}
            if(hexstr[i] == 'A'){
                printf("%s", "1010");}
            if(hexstr[i] == 'B'){
                printf("%s", "1011");}
            if(hexstr[i] == 'C'){
                printf("%s", "1100");}
            if(hexstr[i] == 'D'){
                printf("%s", "1101");}
            if(hexstr[i] == 'E'){
                printf("%s", "1110");}
            if(hexstr[i] == 'F'){
                printf("%s", "1111");}
        }
    }
return 0;
}