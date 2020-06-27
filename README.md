# Steganography

This project is a very basic implementation of digital image steganography. 

The ENCODE program takes a message file of any format and embeds it within a host (.raw) image without changing the visible appearance of the host image, the changes are so small that they are imperceptible to the human eye.

The DECODE program takes an encoded (.raw) image containing a message, extracts the message and saves it to disk.

## Caveats

* At this stage the encoder and decoder can only read RAW image files. However the RAW image file can then be compressed into a png using third party software given you are carfull to use a lossless form of compression.
* The message file must be no larger than 1/3 of the (RAW) host image file size.

## Usage
### Encoder:
` ENCODE 'path/to/host/image.raw' 'path/to/secret_msg/file.anything' 'path/to/desired/output/file.raw' `

### Decoder:
` DECODE 'path/to/image_with_msg.raw' 'path/to/output/file.anything' `
