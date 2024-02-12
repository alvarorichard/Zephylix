package zephylix;
import java.util.List;

import static zephylix.TokenType.*;
//Each grammar rule becomes a method inside this new class:
// expression → equality ;
// equality → comparison ( ( "!=" | "==" ) comparison )* ;
public class Parser {

    //Like the scanner, the parser consumes a flat input sequence
    //only now we’re reading tokens instead of characters
    // We store the list of tokens and use current to point to the next token eagerly waiting to be parsed.

    private final List<Token> tokens;
    private int current = 0;

    Parser(List<Token> tokens) {
        this.tokens = tokens;
    }

// Each method for parsing a grammar rule produces a syntax tree for that rule and returns it to
// the caller. When the body of the rule contains a nonterminal—a reference to another rule—we call
// that other rule’s method.
    private Expr expression() {
        return equality();

    }

    private Expr equality() {
        Expr expr = comparison();

        while (match(BANG_EQUAL, EQUAL_EQUAL)) {
            Token operator = previous();
            Expr right = comparison();
            expr = new Expr.Binary(expr, operator, right);
        }

        return expr;
    }

    private boolean match(TokenType... types) {
        for (TokenType type : types) {
            if (check(type)) {
                advance();
                return true;
            }
        }
        return false;
    }

    private boolean check(TokenType type) {
        if (isAtEnd()) return false;
        return peek().type == type;
    }

    private Token advance() {
        if (!isAtEnd()) current++;
        return previous();
    }

    private boolean isAtEnd() {
        return peek().type == EOF;
    }

    private Token peek() {
        return tokens.get(current);
    }

    private Token previous() {
        return tokens.get(current - 1);
    }


}
