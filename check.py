#!/usr/bin/python
import os, subprocess

def main(opts, args):
    inout = [[], []]
    for _path, _out in zip([opts.input, opts.output], inout):
        with open(_path, 'rb') as fd:
            tmp = []
            for line in fd.readlines():
                if line == '\n':
                    _out.append(''.join(tmp))
                    tmp = []
                else:
                    tmp.append(line)
            _out.append(''.join(tmp))
    for stdin, stdout, idx in zip(inout[0], inout[1], range(opts.num)):
        for arg in args:
            p = subprocess.Popen(arg, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
            p_stdout = p.communicate(stdin)[0]
            print "\n#%d" % idx
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

