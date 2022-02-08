///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           CaseInsensetiveStringExtractor.h                                  
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
//  Creation Date:  30/03/2003                                  
//                                                                           
///////////////////////////////////////////////////////////////////////////////


#if !defined(AFX_CASEINSENSETIVESTRINGEXTRACTOR_H__5B23C61C_E138_4FD4_867B_5ACBBE02CC6B__INCLUDED_)
#define AFX_CASEINSENSETIVESTRINGEXTRACTOR_H__5B23C61C_E138_4FD4_867B_5ACBBE02CC6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StringExtractor.h"

class CCaseInsensetiveStringExtractor : public CStringExtractor  
{
public:
	CCaseInsensetiveStringExtractor (StringsStorage *pStorage = NULL,
                                     ITokenExtractor *pExtractor = NULL);
	virtual ~CCaseInsensetiveStringExtractor ();

    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);

};

#endif // !defined(AFX_CASEINSENSETIVESTRINGEXTRACTOR_H__5B23C61C_E138_4FD4_867B_5ACBBE02CC6B__INCLUDED_)
