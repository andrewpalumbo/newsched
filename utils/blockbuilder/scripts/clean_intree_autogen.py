#!/usr/bin/env python3

# Clean autogenerated meson.build files that live in-tree

import argparse
import glob
import os

def parse_args():
    """Parses commandline args."""
    desc='Clean autogenerated meson.build files that live in-tree'
    parser = argparse.ArgumentParser(description=desc)
    
    parser.add_argument('pathname', help="path to the top of source tree")
    return parser.parse_args()

def main():
    args = parse_args()

    for root, d_names, f_names in os.walk(args.pathname):       
        existing_meson_filename = os.path.join(root,'meson.build')
        if os.path.exists(existing_meson_filename):
            remove = False
            with open(existing_meson_filename, 'r') as meson_file:
                if meson_file.readline().startswith('#autogenerated'):
                    remove = True
            if remove:
                os.remove(existing_meson_filename)



if __name__ == "__main__":
    main()
