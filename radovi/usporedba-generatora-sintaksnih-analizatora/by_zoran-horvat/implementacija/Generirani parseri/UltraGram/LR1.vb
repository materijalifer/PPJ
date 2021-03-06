Option Strict On
Option Explicit On 

Imports System
Imports System.Text
Imports Ust.Parser

Namespace Test

    Public Class UserStackData
        Inherits StackData

        Public Sub New()
            MyBase.New()
        End Sub

        Public Overloads Overrides Sub FinalRelease()
            ' TODO: Place some cleanup code here if nessesary
        End Sub
        ' TODO: Add member variables and methods to store usefull data
    End Class



    Public Class LR1
        Inherits ParserBase

        Public Sub New()
            MyBase.New()
            MyBase.InitDfaTable(LR1DataTable.GetDfaTable())
            MyBase.InitLexer(LR1DataTable.GetLexTable())
        End Sub

        Public Overloads Overrides Function Parse() As Boolean
            Parse = MyBase.Parse
        End Function

#Region "protected"

        Protected Overloads Overrides Function UserAbort() As Boolean
            ' TODO: Place code here...
            '  return true to stop parsing
            '  return false to continue parsing
            UserAbort = False
        End Function
        
        Protected Overloads Overrides Function OnReduce(ByVal nProductionIndex As Integer) As StackData

            Dim data As UserStackData = New UserStackData

            Select Case nProductionIndex
            
                Case LR1DataTable.S_8A19
                ' S : a E a
                	
                
                Case LR1DataTable.S_CD23
                ' S : b E b
                	
                
                Case LR1DataTable.S_8A1A
                ' S : a E b
                	
                
                Case LR1DataTable.S_CD22
                ' S : b E a
                	
                
                Case LR1DataTable.E_2ADE
                ' E : S e
                	
                
                Case LR1DataTable.E_65
                ' E : e
                	
                
                
                Case Else
                    'default code
            End Select
            OnReduce = data
        End Function
        
        Protected Overloads Overrides Sub OnAcceptToken(ByVal nTokenIndex As Integer, ByVal ti As TextInfo)
            'nothing todo
        End Sub
        
        Protected Overloads Overrides Function OnErrorStop(ByVal ei As TErrorInfo, ByVal bCanRecover As Boolean) As Boolean
            If bCanRecover Then
                ' This is recoverable error
                ' TODO: Place code here...
                OnErrorStop = False ' continue parsing... or return "true" to stop parsing
            End If
            OnErrorStop = True ' parsing will be stopped
        End Function

#End Region

    End Class

End Namespace
