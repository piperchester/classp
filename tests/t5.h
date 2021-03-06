/* BEGIN HEADER */
#ifndef t5_INCLUDE_
#define t5_INCLUDE_

#include <assert.h>
#include <unordered_map>
#include <utility>

#include "classp.h"

// Include files generated by bison
#include "t5.yacc.hh"
#include "location.hh"
#include "position.hh"

namespace t5 {
using std::istream;
using std::ostream;
using classp::classpPrint;
using classp::classpFormat;
using classp::AttributeMap;

// Location and state information from the parser.
typedef location ParseState;

class AstNode;
/* BEGIN FORWARD DECLARATIONS */
class Expression;
class Query;
/* END FORWARD DECLARATIONS */

// Base class for t5 AST nodes
class AstNode : public classp::ClasspNode {
 public:
  string className() override { return "AstNode"; }
  AstNode(ParseState parseState)
    : parseState(parseState) {
    }

  // Write out a bracketed form of this AST from the declared syntax.
  virtual void bracketFormat(std::ostream& out, AstNode* self) {
    assert(false);
  }

  ParseState parseState;
};

/* BEGIN CLASS DEFINITIONS */
class Query: public AstNode {
 public:
  string className() override { return "Query"; }
  Query(ParseState parseState, vector<Expression*> select_list, AttributeMap& keyword_args);
  static Query* parse(istream& input, ostream& errors);
  void printMembers(ostream& out) override;
  void format(ostream& out, int precedence) override;

  vector<Expression*> select_list;
  vector<Expression*> from_list;
  Expression* where_clause = nullptr;
  vector<Expression*> group_by;
  bool has_where_clause = false;
};

class Expression: public AstNode {
 public:
  string className() override { return "Expression"; }
  Expression(ParseState parseState, identifier id);
  void printMembers(ostream& out) override;
  void format(ostream& out, int precedence) override;

  identifier id;
};
/* END CLASS DEFINITIONS */

}  // namespace t5
#endif // t5_INCLUDE_

/* END HEADER */
