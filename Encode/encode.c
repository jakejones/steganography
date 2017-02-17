#include <stdio.h>

int main( int argc , char *argv[] ){

	printf("\n");
	
	if(argc >= 2){

		printf("Input:  %s \n", argv[1] );
        printf("Message:  %s \n", argv[2] );
        printf("Output:  %s \n\n", argv[3] );
        
        
        FILE *in  = fopen( argv[1], "r" );
        FILE *msg = fopen( argv[2], "r" );
        FILE *out = fopen( argv[3], "w" );
        
        
        if ( in == NULL ){
            
            printf( "Could not open Image file: %s \n", argv[1] );
        
        } else if( msg == NULL ){
            
            printf("Could not open Message file. \n");
            
        } else if( out == NULL ){
            
            printf("Could not open output file. \n");
            
        } else {
            
            
            long i;
            
            
            // -------------- READ IN MESSAGE ---------
            
            // --- Get Size of Message ---
            
            fseek(msg, 0L, SEEK_END);
            long SIZE = ftell(msg) + 100;
            rewind(msg);
            
            printf("SIZE: %ld\n\n", SIZE);
            
            
            // -- Start Reading in message ---
            int message[SIZE];
            for(int n=0 ; n<SIZE ; n++){
                message[n] = 0;
            }
            int m;
            i = 0;
            while( (m = fgetc(msg)) != EOF  ){
                message[i] = m;
                if( m > 255 ){
                    printf("Too Large:  %d\n",m);
                }
                i++;
            }
            fclose( msg );
            
            
            
            
            
            
            // ------------- READ IMAGE & WRITE MSG TO STEG IMAGE ---------
            int orig;
            int new;
            int digit;
            
            i = 0;
            while  ( (orig = fgetc(in)) != EOF ){
                
                
                new = orig - (orig % 10);
                
                if( (i/3) < SIZE ){
                    
                    switch( i % 3 ){
                            
                        case 0: // -- RED --
                            
                            
                            digit = (  (message[i/3] / 100) % 10  );
                            break;
                            
                            
                        case 1: // -- GREEN --
                            
                            digit = ( (message[i/3] / 10) % 10  );
                            break;
                            
                            
                            
                        case 2: // -- BLUE --
                            
                            digit = (  message[i/3] % 10  );
                            break;
                            
                            
                        default:
                            break;
                    }
                    
                    if( (orig >= 250) && (digit > 5) ){
                        new = 240;
                    }
                    new += digit;
                    
                }
                    
                
                fputc(new,out);
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
