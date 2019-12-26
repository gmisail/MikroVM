import sys

from antlr4 import *

from MikroLexer import MikroLexer
from MikroListener import MikroListener
from MikroParser import MikroParser


def main(argv):
    code = open(argv[1], "r").read()

    input = InputStream(code)
    lexer = MikroLexer(input)
    stream = CommonTokenStream(lexer)
    parser = MikroParser(stream)
    tree = parser.variable()
    
    listener = MikroListener()
    walker = ParseTreeWalker()
    walker.walk(listener, tree)
        
if __name__ == '__main__':
    main(sys.argv)
