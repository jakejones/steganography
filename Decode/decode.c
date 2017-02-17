#include <stdio.h>


int main(int argc, char *argv[]){

    printf("\n");
    
    if(argc >= 2){
        
        printf("Input:  %s \n", argv[1] );
        printf("Output Message:  %s \n\n", argv[2] );
        
        
        
        FILE *in = fopen( argv[1], "r" );
        FILE *out = fopen( argv[2], "w" );
        
        
        if ( in == 0 ){
            
            printf( "Could not open file: %s \n", argv[1] );
            
        } else if( out == 0 ){
            
            printf("Could not open output file. \n");
            
        } else {
            
            
            int read;
            int msg;
            int zeroes = 0;
            
            
            long i = 0;
            while  ( ( read = fgetc(in) ) != EOF )
            {
                
                
                switch( i % 3 ){
                        
                    case 0: // -- RED --
                        
                        msg = (read % 10) * 100;
                        break;
                        
                        
                    case 1: // -- GREEN --
                        
                        msg += (read % 10) * 10;
                        break;
                        
                        
                        
                    case 2: // -- BLUE --
                        
                        msg += (read % 10);
                        if(msg == 0){
                            zeroes++;
                        } else {
                            zeroes = 0;
                        }
                        fputc(msg , out);
                        break;
                        
                        
                    default:
                        break;
                }

                // --- Break after 99 consecutive zeroes ----
                if(zeroes > 99){
                    break;
                }
                
                i++;
                
            }
            
            fclose( in );
            fclose( out );
            
            
        }
        
        
        
        
    } else {
        
        printf(" %s expected an input",argv[0]);
        
    }
    
    
    
    printf("\n\n");


}
