///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           SpaceExtractor.h                                  
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


#if !defined(AFX_SPACEEXTRACTOR_H__D9DD61F0_019F_4EBF_92F8_53AB9CC7797C__INCLUDED_)
#define AFX_SPACEEXTRACTOR_H__D9DD61F0_019F_4EBF_92F8_53AB9CC7797C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CharExtractor.h"

class CSpaceExtractor : public CCharExtractor  
{
public:
	CSpaceExtractor (const char *strTemplate = NULL);
	virtual ~CSpaceExtractor ();

    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);
};

#endif // !defined(AFX_SPACEEXTRACTOR_H__D9DD61F0_019F_4EBF_92F8_53AB9CC7797C__INCLUDED_)
