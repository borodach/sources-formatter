///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           StringExtractor.h                                  
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


#if !defined(AFX_STRINGEXTRACTOR_H__DBCDD939_B236_46CB_8765_3A00D584224D__INCLUDED_)
#define AFX_STRINGEXTRACTOR_H__DBCDD939_B236_46CB_8765_3A00D584224D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "ITokenExtractor.h"

class CStringExtractor : public ITokenExtractor  
{
public:
    typedef std::vector <std::string> StringsStorage; 
	
    CStringExtractor (StringsStorage *pStorage = NULL,
                      ITokenExtractor *pExtractor = NULL);
	virtual ~CStringExtractor ();

    const StringsStorage& GetStorage () const;
    void SetStorage (const StringsStorage *pStorage);
    
    ITokenExtractor* GetSpacesExtractor () const;
    void SetSpacesExtractor ( ITokenExtractor *pExtractor);

    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);
protected:
    StringsStorage m_Storage;
    ITokenExtractor *m_pCommonSpaceExtractor;
};

#endif // !defined(AFX_STRINGEXTRACTOR_H__DBCDD939_B236_46CB_8765_3A00D584224D__INCLUDED_)
