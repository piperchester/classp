/* BEGIN HEADER */
#ifndef prec2_INCLUDE_
#define prec2_INCLUDE_

#include <assert.h>
#include <unordered_map>
#include <utility>

#include "classp.h"

// Include files generated by bison
#include "prec2.yacc.hh"
#include "location.hh"
#include "position.hh"

namespace prec2 {
using std::istream;
using std::ostream;
using classp::classpPrint;
using classp::classpFormat;
using classp::AttributeMap;

// Location and state information from the parser.
typedef location ParseState;

class AstNode;
/* BEGIN FORWARD DECLARATIONS */
class Base;
class Diff;
class Expression;
class Sum;
/* END FORWARD DECLARATIONS */

// Base class for prec2 AST nodes
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
class Expression: public AstNode {
 public:
  string className() override { return "Expression"; }
  Expression(ParseState parseState);
  static Expression* parse(istream& input, ostream& errors);
  void printMembers(ostream& out) override;
  void bracketFormat(ostream& out, AstNode* self) override;

};

class Sum: public Expression {
 public:
  string className() override { return "Sum"; }
  Sum(ParseState parseState, vector<Expression*> args);
  void printMembers(ostream& out) override;
  void format(ostream& out, int precedence) override;

  vector<Expression*> args;
};

class Diff: public Expression {
 public:
  string className() override { return "Diff"; }
  Diff(ParseState parseState, Expression* arg1, Expression* arg2);
  void printMembers(ostream& out) override;
  void format(ostream& out, int precedence) override;

  Expression* arg1 = nullptr;
  Expression* arg2 = nullptr;
};

class Base: public Expression {
 public:
  string className() override { return "Base"; }
  Base(ParseState parseState, int n);
  void printMembers(ostream& out) override;
  void format(ostream& out, int precedence) override;

  int n;
};
/* END CLASS DEFINITIONS */

}  // namespace prec2
#endif // prec2_INCLUDE_

/* END HEADER */
