///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           CharExtractor.h                                  
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


#if !defined(AFX_CHAREXTRACTOR_H__EDDB7D74_B854_46F1_B3D9_975555215535__INCLUDED_)
#define AFX_CHAREXTRACTOR_H__EDDB7D74_B854_46F1_B3D9_975555215535__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ITokenExtractor.h"

class CCharExtractor : public ITokenExtractor  
{
public:
	CCharExtractor (const char *szTemplate = NULL);
    virtual ~CCharExtractor();

    const char* GetTemplate () const;
    void SetTemplate (const char *szTemplate);

    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);
protected:
    std::string m_strTemplate;
};

#endif // !defined(AFX_CHAREXTRACTOR_H__EDDB7D74_B854_46F1_B3D9_975555215535__INCLUDED_)
