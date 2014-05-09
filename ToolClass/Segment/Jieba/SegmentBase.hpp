#ifndef CPPJIEBA_SEGMENTBASE_H
#define CPPJIEBA_SEGMENTBASE_H

#include "TransCode.hpp"
#include "Limonp/logger.hpp"
#include "Limonp/InitOnOff.hpp"
#include "ISegment.hpp"
#include <cassert>


namespace CppJieba
{
    using namespace Limonp;

    //const char* const SPECIAL_CHARS = " \t\n";
#ifndef CPPJIEBA_GBK
    const UnicodeValueType SPECIAL_SYMBOL[] = {32u, 9u, 10u, 12290u, 65292u};  
#else
    const UnicodeValueType SPECIAL_SYMBOL[] = {32u, 9u, 10u};  
#endif

    class SegmentBase: public ISegment, public InitOnOff
    {
        public:
            SegmentBase(){_loadSpecialSymbols();};
            virtual ~SegmentBase(){};
        private:
            unordered_set<UnicodeValueType> _specialSymbols;
        private:
            void _loadSpecialSymbols()
            {
                size_t size = sizeof(SPECIAL_SYMBOL)/sizeof(*SPECIAL_SYMBOL);
                for(size_t i = 0; i < size; i ++)
                {
                    _specialSymbols.insert(SPECIAL_SYMBOL[i]);
                }
                assert(_specialSymbols.size());
            }

        public:
            virtual bool cut(Unicode::const_iterator begin, Unicode::const_iterator end, vector<string>& res) const = 0;
            virtual bool cut(const string& str, vector<string>& res)const
            {
                assert(_getInitFlag());

                Unicode unicode;
                TransCode::decode(str, unicode);
                res.clear();
                
                Unicode::const_iterator left = unicode.begin();
                Unicode::const_iterator right = unicode.begin();
                
                string oneword;
                while(right != unicode.end())
                {
                    if(isIn(_specialSymbols, *right))
                    {
                        if(left != right)
                        {
                            cut(left, right, res);
                        }
                        TransCode::encode(right, right + 1, oneword);
                        res.push_back(oneword);
                        right ++;
                        left = right;
                    }
                    else
                    {
                        right ++;
                    }
                }
                if(left != right)
                {
                    cut(left, right, res);
                }
                
                return true;
            }
    };
}

#endif
