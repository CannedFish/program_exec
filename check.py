#!/usr/bin/python
import os, subprocess

def main(opts, args):
    ins = []
    outs = []
    with open(opts.input, 'rb') as fd:
        for line in fd.readlines():
            ins.append(line)
    with open(opts.output, 'rb') as fd:
        for line in fd.readlines():
            outs.append(line)
    n = len(ins)/opts.num
    for stdin, stdout in \
            zip(['\n'.join(ins[i:i+n]) for i in range(0, len(ins), n)], \
            ['\n'.join(outs[i:i+n]) for i in range(0, len(outs), n)]):
        for arg in args:
            p = subprocess.Popen(arg, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
            p_stdout = p.communicate(stdin)[0]
            print "exec:"
            print arg
            print "stdin:"
            print stdin
            print "stdout expected is:"
            print stdout
            print "stdout executed is:"
            print p_stdout
            print "The answer is: %s" % ("Right" if stdout == p_stdout else "Wrong")

if __name__ == '__main__':
    from optparse import OptionParser

    usage = "Usage: %prog [options] args1 args2 ..."
    parser = OptionParser(usage)
    parser.add_option("-i", "--input", dest="input"
            , type="string", action="store"
            , help="Path of input file"
            , default="./input.dat")
    parser.add_option("-o", "--output", dest="output"
            , type="string", action="store"
            , help="Path of output file"
            , default="./output.dat")
    parser.add_option("-n", "--num", dest="num"
            , type="int", action="store"
            , help="Number of instance"
            , default=1)

    opts, args = parser.parse_args()

    if len(args) < 1:
        parser.error("No executalbe file to check.")
    if not os.path.exists(opts.input):
        parser.error("No such file: %s" % opts.input)
    if not os.path.exists(opts.output):
        parser.error("No such file: %s" % opts.output)
    for arg in args:
        if not os.path.exists(arg):
            parser.error("No such file: %s" % arg)

    main(opts, args)

