#!/usr/bin/python

import random
import argparse

parser = argparse.ArgumentParser(description='Random Phonebook format generator for test data, created by Kevin Cyu')

parser.add_argument('-s','--strlen',help='Range of string length prepare to generate',
                    type=int,action="store",default=20)
parser.add_argument('-c','--char',help='Range of character, 1~n, will turn into ASCII code',
                    type=int,action="store",default=127)
parser.add_argument('-b','--booksize',help='The size of result phonebook',
                    type=int,action="store",default=1000)
parser.add_argument('-o','--output',help='Output filename',
                    type=str,action="store",default='phonebook')
parser.add_argument('-t','--type',help='Type of output file',
                    type=str,action="store",default='txt')
parser.add_argument('-l','--location',help='Output file location',
                    type=str,action="store",default='.')

args = parser.parse_args()

def main():
    print "Welcome to use Random Phonebook format generator!"
    print 

    print "===== Specified Parameter Preview ======"
    print "The string length range: %d, the character range: %d" % (args.strlen, args.char)
    print "The size of this phonebook: %d" % args.booksize
    print "The output directory: %s" % args.location
    print "And the output filename(with extension): %s.%s" % (args.output, args.type)
    print 

    booksize = args.booksize
    result = []
    filename = args.location + '/' + args.output + '.' + args.type

    # Start generation
    for i in range(0,args.booksize):
        # each string start from here 
        strlen_range = random.randint(1,args.strlen)
        result_str = ''
        for j in range(0,strlen_range):
            # each character
            cur_char = random.randint(33,args.char)
            result_str += str(chr(cur_char))
        # after generate, append it into result
        result.append(result_str)

    print len(result)
    # write into file
    with open(filename,'w') as fp:
        count=0
        for rnd_str in result:
            count+=1
            fp.write(rnd_str)
            if count != booksize:
                fp.write('\n')

        fp.close()

if __name__ == '__main__':
    main()