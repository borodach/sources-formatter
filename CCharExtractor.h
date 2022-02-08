///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           CCharExtractor.h                                  
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


#if !defined(AFX_CCHAREXTRACTOR_H__DF15CD89_5DC8_4CB9_A6D3_11C35DA891FC__INCLUDED_)
#define AFX_CCHAREXTRACTOR_H__DF15CD89_5DC8_4CB9_A6D3_11C35DA891FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ITokenExtractor.h"

class CCCharExtractor : public ITokenExtractor  
{
public:
	CCCharExtractor();
	virtual ~CCCharExtractor();

    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);
};

#endif // !defined(AFX_CCHAREXTRACTOR_H__DF15CD89_5DC8_4CB9_A6D3_11C35DA891FC__INCLUDED_)
