///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           PascalGramma.h                                  
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


#if !defined(AFX_PASCALGRAMMA_H__FEE6D327_7E7F_46E0_98AD_3039D5701E39__INCLUDED_)
#define AFX_PASCALGRAMMA_H__FEE6D327_7E7F_46E0_98AD_3039D5701E39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IGramma.h"
#include "CharExtractor.h"

#include <vector>

enum EPascalLexemTypes
{
    eMultiLineComment = 1,
    eSingleLineComment,
    eMultiCharOperation,
    eString,
    eComma,
    eSpace,
    eBracket,
    eSingleCharOperation,
    eBeginBlock,
    eEndBlock,
    eEndTry,
    eClassMemberAccessSpecifier
};


class CPascalGramma : public IGramma  
{
public:
    typedef std::vector <SLexemma> LexemmaStorage;
    typedef std::vector <SToken> TokenStorage;

	CPascalGramma ();
	virtual ~CPascalGramma ();

    unsigned GetIndentSize ();
    void SetIndentSize (unsigned nSize);
    int GetCurrentIndent ();
    void SetCurrentIndent (int nIndent);
    int GetDoNotUseTabsFlag ();
    void SetDoNotUseTabsFlag (int bFlag);
    int GetTabSize ();
    void SetTabSize (int nTabSize);

    virtual int GetLexemmaCount ();
    virtual SLexemma* GetNthLexemma (int nIdx);
    virtual void PushToken (const std::string &strValue, 
                            LexemmaType nType = PLAIN_TEXT);
    virtual void ClearTokenList ();
    virtual void GenerateText (std::string &strValue);
          
    static void RemoveTabs (std::string &strData, int nTabSize);

protected:
    static LexemmaStorage m_Lexemmas;
    TokenStorage m_Tokens;
    static CCharExtractor m_DelimerExtractor;
    unsigned m_nIndentSize;
    int m_nIndent;
    int m_bDoNotUseTabs;
    int m_nTabSize;
};

#endif // !defined(AFX_PASCALGRAMMA_H__FEE6D327_7E7F_46E0_98AD_3039D5701E39__INCLUDED_)
