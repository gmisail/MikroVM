# Generated from Mikro.g4 by ANTLR 4.7.1
# encoding: utf-8
from antlr4 import *
from io import StringIO
from typing.io import TextIO
import sys

def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\7")
        buf.write("\n\4\2\t\2\3\2\3\2\3\2\3\2\3\2\3\2\2\2\3\2\2\2\2\b\2\4")
        buf.write("\3\2\2\2\4\5\7\3\2\2\5\6\7\5\2\2\6\7\7\4\2\2\7\b\7\6\2")
        buf.write("\2\b\3\3\2\2\2\2")
        return buf.getvalue()


class MikroParser ( Parser ):

    grammarFileName = "Mikro.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'var'", "'='" ]

    symbolicNames = [ "<INVALID>", "VAR", "EQUALS", "NAME", "NUMBER", "WHITESPACE" ]

    RULE_variable = 0

    ruleNames =  [ "variable" ]

    EOF = Token.EOF
    VAR=1
    EQUALS=2
    NAME=3
    NUMBER=4
    WHITESPACE=5

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.7.1")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None



    class VariableContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def VAR(self):
            return self.getToken(MikroParser.VAR, 0)

        def NAME(self):
            return self.getToken(MikroParser.NAME, 0)

        def EQUALS(self):
            return self.getToken(MikroParser.EQUALS, 0)

        def NUMBER(self):
            return self.getToken(MikroParser.NUMBER, 0)

        def getRuleIndex(self):
            return MikroParser.RULE_variable

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterVariable" ):
                listener.enterVariable(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitVariable" ):
                listener.exitVariable(self)




    def variable(self):

        localctx = MikroParser.VariableContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_variable)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 2
            self.match(MikroParser.VAR)
            self.state = 3
            self.match(MikroParser.NAME)
            self.state = 4
            self.match(MikroParser.EQUALS)
            self.state = 5
            self.match(MikroParser.NUMBER)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx





