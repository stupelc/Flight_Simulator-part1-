cmake_minimum_required(VERSION 3.12)
project(progect)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(progect main.cpp Expression.cpp Expression.h Var.cpp Var.h Number.cpp Number.h Plus.cpp Plus.h Pow.cpp Pow.h Mult.cpp Mult.h Minus.cpp Minus.h Div.cpp Div.h Command.cpp Command.h CommandTable.cpp CommandTable.h BinaryExpression.cpp BinaryExpression.h Var.cpp Var.h ExpressionHeaders.h ExpressionDetect.cpp ExpressionDetect.h Reader.cpp Reader.h OpenDataServer.cpp OpenDataServer.h ConnectCommand.cpp ConnectCommand.h VarCommand.cpp VarCommand.h Parser.cpp Parser.h OtherFunctions.cpp OtherFunctions.h CommandExpression.cpp CommandExpression.h UnaryExpression.cpp UnaryExpression.h Neg.cpp Neg.h LoopCommand.cpp LoopCommand.h ServerSocket.cpp ServerSocket.h SymbolTable.cpp SymbolTable.h SleepCommand.cpp SleepCommand.h ClientSocket.cpp ClientSocket.h PrintCommand.cpp PrintCommand.h IfCommand.cpp IfCommand.h PlacementCommand.cpp PlacementCommand.h equalsCommand.cpp equalsCommand.h)