package zephylix;
import java.util.List;

import static zephylix.TokenType.*;
public class Parser {
    private final List<Token> tokens;
    private int current = 0;

    Parser(List<Token> tokens) {
        this.tokens = tokens;
    }
}
