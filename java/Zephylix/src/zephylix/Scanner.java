package zephylix;

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

import static zephylix.TokenType.*;

public class Scanner {
    private final String source;
    private final List<Token> tokens = new ArrayList<>();

    Scanner(String source) {
        this.source = source;
    }

    List<Token> scanTokens() {
        int start = 0;
        int current = 0;
        int line = 1;
        while (current < source.length()) {
            start = current;
            scanToken();
        }
        tokens.add(new Token(EOF, "", null, line));
        return tokens;
    }
}
