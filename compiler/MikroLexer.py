# Generated from Mikro.g4 by ANTLR 4.7.1
from antlr4 import *
from io import StringIO
from typing.io import TextIO
import sys


def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\7")
        buf.write("\62\b\1\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t")
        buf.write("\7\3\2\3\2\3\2\3\2\3\3\3\3\3\4\3\4\7\4\30\n\4\f\4\16\4")
        buf.write("\33\13\4\3\5\3\5\3\6\6\6 \n\6\r\6\16\6!\3\6\3\6\6\6&\n")
        buf.write("\6\r\6\16\6\'\5\6*\n\6\3\7\6\7-\n\7\r\7\16\7.\3\7\3\7")
        buf.write("\2\2\b\3\3\5\4\7\5\t\2\13\6\r\7\3\2\7\4\2C\\c|\5\2\62")
        buf.write(";C\\c|\3\2\62;\4\2..\60\60\5\2\13\f\16\17\"\"\2\65\2\3")
        buf.write("\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\13\3\2\2\2\2\r\3\2")
        buf.write("\2\2\3\17\3\2\2\2\5\23\3\2\2\2\7\25\3\2\2\2\t\34\3\2\2")
        buf.write("\2\13\37\3\2\2\2\r,\3\2\2\2\17\20\7x\2\2\20\21\7c\2\2")
        buf.write("\21\22\7t\2\2\22\4\3\2\2\2\23\24\7?\2\2\24\6\3\2\2\2\25")
        buf.write("\31\t\2\2\2\26\30\t\3\2\2\27\26\3\2\2\2\30\33\3\2\2\2")
        buf.write("\31\27\3\2\2\2\31\32\3\2\2\2\32\b\3\2\2\2\33\31\3\2\2")
        buf.write("\2\34\35\t\4\2\2\35\n\3\2\2\2\36 \5\t\5\2\37\36\3\2\2")
        buf.write("\2 !\3\2\2\2!\37\3\2\2\2!\"\3\2\2\2\")\3\2\2\2#%\t\5\2")
        buf.write("\2$&\5\t\5\2%$\3\2\2\2&\'\3\2\2\2\'%\3\2\2\2\'(\3\2\2")
        buf.write("\2(*\3\2\2\2)#\3\2\2\2)*\3\2\2\2*\f\3\2\2\2+-\t\6\2\2")
        buf.write(",+\3\2\2\2-.\3\2\2\2.,\3\2\2\2./\3\2\2\2/\60\3\2\2\2\60")
        buf.write("\61\b\7\2\2\61\16\3\2\2\2\b\2\31!\').\3\b\2\2")
        return buf.getvalue()


class MikroLexer(Lexer):

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    VAR = 1
    EQUALS = 2
    NAME = 3
    NUMBER = 4
    WHITESPACE = 5

    channelNames = [ u"DEFAULT_TOKEN_CHANNEL", u"HIDDEN" ]

    modeNames = [ "DEFAULT_MODE" ]

    literalNames = [ "<INVALID>",
            "'var'", "'='" ]

    symbolicNames = [ "<INVALID>",
            "VAR", "EQUALS", "NAME", "NUMBER", "WHITESPACE" ]

    ruleNames = [ "VAR", "EQUALS", "NAME", "DIGIT", "NUMBER", "WHITESPACE" ]

    grammarFileName = "Mikro.g4"

    def __init__(self, input=None, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.7.1")
        self._interp = LexerATNSimulator(self, self.atn, self.decisionsToDFA, PredictionContextCache())
        self._actions = None
        self._predicates = None


