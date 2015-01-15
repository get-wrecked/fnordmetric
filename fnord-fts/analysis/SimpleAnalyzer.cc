/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2014 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "fnord-fts/fts.h"
#include "fnord-fts/analysis/SimpleAnalyzer.h"
#include "fnord-fts/analysis/LowerCaseTokenizer.h"

namespace fnord {
namespace fts {

SimpleAnalyzer::~SimpleAnalyzer() {
}

TokenStreamPtr SimpleAnalyzer::tokenStream(const String& fieldName, const ReaderPtr& reader) {
    return newLucene<LowerCaseTokenizer>(reader);
}

TokenStreamPtr SimpleAnalyzer::reusableTokenStream(const String& fieldName, const ReaderPtr& reader) {
    TokenizerPtr tokenizer(std::dynamic_pointer_cast<Tokenizer>(getPreviousTokenStream()));
    if (!tokenizer) {
        tokenizer = newLucene<LowerCaseTokenizer>(reader);
        setPreviousTokenStream(tokenizer);
    } else {
        tokenizer->reset(reader);
    }
    return tokenizer;
}

}

}