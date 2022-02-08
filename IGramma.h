///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           IGramma.h                                  
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


#if !defined(AFX_IGRAMMA_H__F9211C2D_8DF6_4265_855E_E098379105A3__INCLUDED_)
#define AFX_IGRAMMA_H__F9211C2D_8DF6_4265_855E_E098379105A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

#include "ITokenExtractor.h"

typedef int LexemmaType;
#define PLAIN_TEXT  ((LexemmaType) 0)

class IGramma  
{
public:
    struct SLexemma
    {
        LexemmaType m_nType;
        ITokenExtractor *m_pExtractor;
    };

    struct SToken
    {
        LexemmaType m_nType;
        std::string m_strValue;
        int nState;
    };

	virtual ~IGramma ();
    
    virtual int GetLexemmaCount () = 0;
    virtual SLexemma* GetNthLexemma (int nIdx) = 0;
    virtual void PushToken (const std::string &strValue, 
                            LexemmaType nType = PLAIN_TEXT) = 0;
    virtual void ClearTokenList () = 0;
    virtual void GenerateText (std::string &strValue) = 0;
};

#endif // !defined(AFX_IGRAMMA_H__F9211C2D_8DF6_4265_855E_E098379105A3__INCLUDED_)
