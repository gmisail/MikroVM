# Generated from Mikro.g4 by ANTLR 4.7.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .MikroParser import MikroParser
else:
    from MikroParser import MikroParser

# This class defines a complete listener for a parse tree produced by MikroParser.
class MikroListener(ParseTreeListener):

    # Enter a parse tree produced by MikroParser#variable.
    def enterVariable(self, ctx:MikroParser.VariableContext):
        print("assigning " + ctx.NAME().getText() + " to " + ctx.NUMBER().getText())

    # Exit a parse tree produced by MikroParser#variable.
    def exitVariable(self, ctx:MikroParser.VariableContext):
        pass


