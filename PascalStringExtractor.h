///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           PascalStringExtractor.h                                  
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


#if !defined(AFX_PASCALSTRINGEXTRACTOR_H__02AA45A5_53D5_48CD_BA00_53FAACC7A25D__INCLUDED_)
#define AFX_PASCALSTRINGEXTRACTOR_H__02AA45A5_53D5_48CD_BA00_53FAACC7A25D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ITokenExtractor.h"

class CPascalStringExtractor : public ITokenExtractor  
{
public:
	CPascalStringExtractor ();
	virtual ~CPascalStringExtractor ();

     virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);

};

#endif // !defined(AFX_PASCALSTRINGEXTRACTOR_H__02AA45A5_53D5_48CD_BA00_53FAACC7A25D__INCLUDED_)
