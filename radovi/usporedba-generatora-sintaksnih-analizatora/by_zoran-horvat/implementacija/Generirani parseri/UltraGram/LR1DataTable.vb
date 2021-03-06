Option Strict On
Option Explicit On 

Imports System
Imports System.Text
Imports Ust.Parser

Namespace Test

    Public Class LR1DataTable
#Region "Private"

        Private Shared anLexTable As Integer() = _
        { _
        	3,412,56,134,746,256,32,90,0,0,5,0,5,0,1,2147483647, _
        	8,0,4,0,2,0,32,2,0,10,2,0,9,2,0,13, _
        	1,2,1,101,2,2,1,97,3,2,1,98,4,24,0,0, _
        	1,0 _
        }

        Private Shared anDfaTable As Integer() = _
        { _
        	4,0,7,9,17,18,18,0,4,0,0,21,1,2,5,2, _
        	0,0,1,2,2,0,1,3,17,0,1,6,1,0,0,0, _
        	1,1,5,0,0,1,3,4,0,1,5,0,1,3,5,2, _
        	0,2,1,1,16,0,1,2,8,0,1,3,12,0,1,6, _
        	6,0,1,7,3,0,1,2,5,0,0,3,1,2,4,0, _
        	1,3,5,0,1,1,5,0,0,4,2,4,1,3,6,0, _
        	1,1,5,0,0,5,2,4,3,3,6,0,1,1,5,0, _
        	0,6,1,1,7,0,1,2,5,0,0,7,2,2,5,2, _
        	7,0,2,3,5,2,7,0,1,3,5,2,0,8,1,1, _
        	16,0,1,2,8,0,1,3,12,0,1,6,6,0,1,7, _
        	9,0,1,2,5,0,0,9,1,2,10,0,1,3,11,0, _
        	1,1,5,0,0,10,2,1,1,3,6,0,1,1,5,0, _
        	0,11,2,1,3,3,6,0,1,3,5,2,0,12,1,1, _
        	16,0,1,2,8,0,1,3,12,0,1,6,6,0,1,7, _
        	13,0,1,2,5,0,0,13,1,2,14,0,1,3,15,0, _
        	1,1,5,0,0,14,2,1,4,3,6,0,1,1,5,0, _
        	0,15,2,1,2,3,6,0,1,2,5,0,0,16,2,2, _
        	6,1,7,0,2,3,6,1,7,0,1,3,5,2,0,17, _
        	1,1,16,0,1,2,8,0,1,3,12,0,1,6,6,0, _
        	1,7,18,0,1,2,5,0,0,18,1,2,19,0,1,3, _
        	20,0,1,1,5,0,0,19,2,4,4,3,6,0,1,1, _
        	5,0,0,20,2,4,2,3,6,0 _
        }

        Private Shared aTokName As TokName() = _
        { _
		New TokName( "wspace", "" ), _
		New TokName( "e", "e" ), _
		New TokName( "a", "a" ), _
		New TokName( "b", "b" ), _
		New TokName( "_EOF_", "_EOF_" ) _        
        }
#End Region

#Region "public const"
        Public Const S_8A19 As Integer			= 1
        Public Const S_CD23 As Integer			= 2
        Public Const S_8A1A As Integer			= 3
        Public Const S_CD22 As Integer			= 4
        Public Const E_2ADE As Integer			= 5
        Public Const E_65 As Integer			= 6
        
#End Region


        Public Shared Function GetLexTable() As Integer()
            GetLexTable = anLexTable
        End Function

        Public Shared Function GetDfaTable() As Integer()
            GetDfaTable = anDfaTable
        End Function

        Public Shared Function TokName() As TokName()
            TokName = aTokName
        End Function


    End Class
End Namespace
