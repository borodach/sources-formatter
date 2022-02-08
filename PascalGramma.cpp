///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           PascalGramma.cpp                                  
//
//  Facility:                                                                
//                                                                           
//                                                                           
//  Abstract:                                                                
//                                                                           
//  Environment:    VC 6.0                                                   
//                                                                           
//  Author:         Зайцев С. А.                                                          
//                                                                           
//  Creation Date:  29/03/2003                                  
//                                                                           
///////////////////////////////////////////////////////////////////////////////


#include "PascalGramma.h"
#include "MultiLineCommentExtractor.h"
#include "SingleLineCommentExtractor.h"
#include "CharExtractor.h"
#include "CaseInsensetiveStringExtractor.h"
#include "PascalStringExtractor.h"
#include "SpaceExtractor.h"

#define DELIMER_CHARS " \t\r\\\'\",.;/*-+<>=()[]!?{}~|"


CCharExtractor CPascalGramma::m_DelimerExtractor (DELIMER_CHARS);

CPascalGramma::LexemmaStorage CPascalGramma::m_Lexemmas;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPascalGramma::CPascalGramma (): m_nIndent (0), m_nIndentSize (4),
m_bDoNotUseTabs (1), m_nTabSize (4)
{
    SLexemma lex;

    lex.m_nType = eMultiLineComment;
    lex.m_pExtractor = new CMultiLineCommentExtractor ("{", "}");
    m_Lexemmas.push_back (lex);


    lex.m_nType = eSingleLineComment;
    lex.m_pExtractor = new CSingleLineCommentExtractor ("//");
    m_Lexemmas.push_back (lex);
  
    CStringExtractor::StringsStorage mcOperations;
    mcOperations.push_back (">=");
    mcOperations.push_back ("<=");
    mcOperations.push_back ("<>");
    mcOperations.push_back (":=");
    lex.m_nType = eMultiCharOperation;
    lex.m_pExtractor = new CStringExtractor (&mcOperations, NULL);
    m_Lexemmas.push_back (lex);

    lex.m_nType = eComma;
    lex.m_pExtractor = new CCharExtractor (",:");
    m_Lexemmas.push_back (lex);
    
    lex.m_nType = eSpace;
    lex.m_pExtractor = new CSpaceExtractor (" \t\r");
    m_Lexemmas.push_back (lex);

    lex.m_nType = eBracket;
    lex.m_pExtractor = new CCharExtractor ("([");
    m_Lexemmas.push_back (lex);
    
    lex.m_nType = eString;
    lex.m_pExtractor = new CPascalStringExtractor;
    m_Lexemmas.push_back (lex);

    lex.m_nType = eSingleCharOperation;
    lex.m_pExtractor = new CCharExtractor ("+-*/<>=");
    m_Lexemmas.push_back (lex);

    CStringExtractor::StringsStorage beginBlock;
    beginBlock.push_back ("begin");
    beginBlock.push_back ("try");
    beginBlock.push_back ("case");
    beginBlock.push_back ("class");
    beginBlock.push_back ("record");
    lex.m_nType = eBeginBlock;
    lex.m_pExtractor = new CCaseInsensetiveStringExtractor (&beginBlock, 
        &m_DelimerExtractor);
    m_Lexemmas.push_back (lex);

    CStringExtractor::StringsStorage endBlock;
    endBlock.push_back ("end");
    endBlock.push_back ("End");
    lex.m_nType = eEndBlock;
    lex.m_pExtractor = new CStringExtractor (&endBlock, &m_DelimerExtractor);
    m_Lexemmas.push_back (lex);

    CStringExtractor::StringsStorage endTry;
    endTry.push_back ("ecxept");
    endTry.push_back ("finally");
    lex.m_nType = eEndTry;
    lex.m_pExtractor = new CCaseInsensetiveStringExtractor (&endTry, 
        &m_DelimerExtractor);
    m_Lexemmas.push_back (lex);

    CStringExtractor::StringsStorage acessSpecifiers;
    acessSpecifiers.push_back ("public");
    acessSpecifiers.push_back ("protected");
    acessSpecifiers.push_back ("private");
    acessSpecifiers.push_back ("published");
    lex.m_nType = eClassMemberAccessSpecifier;
    lex.m_pExtractor = new CCaseInsensetiveStringExtractor (&acessSpecifiers, 
        &m_DelimerExtractor);
    m_Lexemmas.push_back (lex);
}

CPascalGramma::~CPascalGramma()
{
    int nSize = m_Lexemmas.size (); 
    for (int i = 0; i < nSize; ++i)
        delete m_Lexemmas [i].m_pExtractor;

    m_Lexemmas.clear ();
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::GetIndentSize                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

unsigned CPascalGramma::GetIndentSize ()
{
    return m_nIndentSize;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::SetIndentSize                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CPascalGramma::SetIndentSize (unsigned nSize)
{
    m_nIndentSize = nSize;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::GetCurrentIndent                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

int CPascalGramma::GetCurrentIndent ()
{
    return m_nIndent;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::SetCurrentIndent                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CPascalGramma::SetCurrentIndent (int nIndent)
{
    m_nIndent = nIndent;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::GetDoNotUseTabsFlag                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

int CPascalGramma::GetDoNotUseTabsFlag ()
{
    return m_bDoNotUseTabs;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::SetDoNotUseTabsFlag                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CPascalGramma::SetDoNotUseTabsFlag (int bFlag)
{
    m_bDoNotUseTabs = bFlag;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::GetTabSize                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

int CPascalGramma::GetTabSize ()
{
    return m_nTabSize;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::SetTabSize                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CPascalGramma::SetTabSize (int nTabSize)
{
    m_nTabSize = nTabSize;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::GetLexemmaCount                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

int CPascalGramma::GetLexemmaCount ()
{
    return m_Lexemmas.size ();
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::GetNthLexemma                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

IGramma::SLexemma* CPascalGramma::GetNthLexemma (int nIdx)
{
    if (nIdx < 0 || nIdx >= m_Lexemmas.size ())
        return NULL;

    return &(m_Lexemmas [nIdx]);
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::ClearTokenList                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////
   
void CPascalGramma::ClearTokenList ()
{
    m_Tokens.clear ();
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::PushToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CPascalGramma::PushToken (const std::string &strValue, 
                               LexemmaType nType/* = PLAIN_TEXT*/)
{
    SToken token;
    token.m_nType = nType;
    token.m_strValue = strValue;
    token.nState = 0;
    m_Tokens.push_back (token);
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::GenerateText                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CPascalGramma::GenerateText (std::string &strValue)
{
    int nIndent = m_nIndent;
    strValue.resize (0);
    int nSize = m_Tokens.size ();

    for (int i = 0; i < nSize; ++i)
    {
        switch (m_Tokens.at (i).m_nType)
        {
        case eSpace:
            if (m_bDoNotUseTabs)
            {
                RemoveTabs (m_Tokens.at (i).m_strValue, m_nTabSize);
            }
            if (i == 0)
            {
                //strValue += m_Tokens.at (i).m_strValue;
            }
            else
            {
                if (i < nSize - 1)
                {
                    if (m_Tokens.at (i + 1).m_nType != eComma && 
                        m_Tokens.at (i - 1).m_nType != eBracket)
                    {
                        strValue += ' ';
                    }
                }
                else
                {
                    if (m_Tokens.at (i - 1).m_nType != eBracket)
                    {
                        strValue += ' ';
                    }
                }
                
            }
            break;
        case eComma:
            strValue += m_Tokens.at (i).m_strValue;
            if (i < nSize - 1)
            {
                if (m_Tokens.at (i + 1).m_nType != eSpace)
                {
                    strValue += ' ';
                }
            }
            break;

        case eMultiCharOperation:
        case eSingleCharOperation:

            if (i != 0 && 
                m_Tokens.at (i - 1).m_nType != eSpace)
            {
                strValue += ' ';
            }

            strValue += m_Tokens.at (i).m_strValue;
            
            if (i < nSize - 1 &&
                m_Tokens.at (i + 1).m_nType != eSpace)
            {
                strValue += ' ';
            }

            break;
        case eBracket:
            if (i != 0 && 
                m_Tokens.at (i - 1).m_nType != eSpace &&
                m_Tokens.at (i - 1).m_nType != eBracket)
            {
                strValue += ' ';
            }
            strValue += m_Tokens.at (i).m_strValue;

            break;
        
        case eBeginBlock:
            strValue += m_Tokens.at (i).m_strValue;
            m_nIndent += m_nIndentSize;
            break;

        case eEndBlock:
            strValue += m_Tokens.at (i).m_strValue;
            m_nIndent -= m_nIndentSize;
            nIndent -= m_nIndentSize;
            if (m_nIndent < 0) m_nIndent = 0;
            if (nIndent < 0) nIndent = 0;
            break;

        case eEndTry:
            strValue += m_Tokens.at (i).m_strValue;
            nIndent -= m_nIndentSize;
            if (nIndent < 0) nIndent = 0;
            break;

        case eClassMemberAccessSpecifier:
            strValue += m_Tokens.at (i).m_strValue;
            nIndent -= m_nIndentSize;
            break;
        default:
            strValue += m_Tokens.at (i).m_strValue;
        }
    }

    strValue.insert ((int)0, nIndent, (char)' ');
    
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalGramma::RemoveTabs                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CPascalGramma::RemoveTabs (std::string &strData, int nTabSize)
{
    std::string strDataWithoutTabs;
    int nLen = strData.length ();
    for (int nIdx = 0; nIdx < nLen; ++nIdx)
    {
        if (strData [nIdx] != '\t')
        {
            strDataWithoutTabs += strData [nIdx];
            continue;
        }
        strDataWithoutTabs.append (nTabSize, ' ');
    }
    
}