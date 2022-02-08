///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           CStringExtractor.h                                  
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


#if !defined(AFX_CSTRINGEXTRACTOR_H__A37611F5_89A8_423F_ADEB_FE4D0F691AEA__INCLUDED_)
#define AFX_CSTRINGEXTRACTOR_H__A37611F5_89A8_423F_ADEB_FE4D0F691AEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ITokenExtractor.h"

class CCStringExtractor : public ITokenExtractor  
{
public:
	CCStringExtractor ();
	virtual ~CCStringExtractor ();

    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);
};

#endif // !defined(AFX_CSTRINGEXTRACTOR_H__A37611F5_89A8_423F_ADEB_FE4D0F691AEA__INCLUDED_)
