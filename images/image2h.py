#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""A script to convert an image to a header file for the microcontroller"""

import sys
import pathlib
import argparse

from PIL import Image

def get_arguments():
    """Handle terminal arguments"""
    parser = argparse.ArgumentParser(description='Convert an image to a header file for the microcontroller.')
    parser.add_argument('image', type=pathlib.Path, help='the image to convert')
    parser.add_argument('-o', '--output', metavar='<file>', type=argparse.FileType('w'), default='out.h', help='place the output into <file>')
    parser.add_argument('-p', '--preview', metavar='<file>', type=pathlib.Path, default='result.png', help='save the preview image as <file>')
    args = parser.parse_args()
    return args.image, args.output, args.preview

def convert_image_to_h(image, output, preview):
    """Convert an image to a header file for the microcontroller.

    Parameters
    ----------
    image : Path
        The image to convert
    output : file pointer
        The header file to write to
    preview : Path
        A preview of the final image
    """
    image_file = Image.open(image)
    image_file = image_file.convert('1') # Convert image to black and white
    image_file = image_file.resize((104, 115))
    image_file.save(preview)
    pixels = image_file.tobytes()
    for y in range(115):
        output.write('{')
        for x in range(13):
            byte = pixels[x + y * 13]
            output.write(str(byte))
            if x != 12: output.write(', ')
        output.write('}')
        if y != 114: output.write(',\n')

if __name__ == '__main__':
    convert_image_to_h(*get_arguments())
