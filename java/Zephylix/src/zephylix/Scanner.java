package zephylix;

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

import static java.lang.Character.isDigit;
import static zephylix.TokenType.*;



public class Scanner {
    private final String source;
    private final List<Token> tokens = new ArrayList<>();
    private int start = 0;
    private int current = 0;
    private int line = 1;

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
//Método principal que percorre o source, identifica tokens, e os adiciona à lista tokens.
    private boolean isAtEnd() {
        return current >= source.length();
    }

    //Em cada volta do loop, verificamos um único token.
    //Este é o verdadeiro coração do scanner.
    //Começaremos de forma simples.
    //Imagine se cada lexema tivesse apenas um caractere.
    //Tudo o que você precisa fazer é consumir o próximo caractere e escolher um tipo de token para ele.
    //Vários lexemas são apenas um único caractere no Lox, então vamos começar com eles.

    //Método auxiliar que verifica se o scanner alcançou o fim do código fonte.
    private void scanToken(){
        char c = advance();
        switch (c){
            case '(': addToken(LEFT_PAREN); break;
            case ')': addToken(RIGHT_PAREN); break;
            case '{': addToken(LEFT_BRACE); break;
            case '}': addToken(RIGHT_BRACE); break;
            case ',': addToken(COMMA); break;
            case '.': addToken(DOT); break;
            case '-': addToken(MINUS); break;
            case '+': addToken(PLUS); break;
            case ';': addToken(SEMICOLON); break;
            case '*': addToken(STAR); break;
            case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
            case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL); break;
            case '<': addToken(match('=') ? LESS_EQUAL : LESS); break;
            case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;
            case '/':
                if (match('/')) {
                    while (peek() != '\n' && !isAtEnd()) advance();
                }else if (match('*')){
                        //comentário de bloco
                        blockComment();

                } else {
                    addToken(SLASH);
                }
                break;
            case ' ':
            case '\r':
            case '\t':
                break;
            case '\n':
                line++;
                break;
            case '"': string(); break;
            default:
                if (isDigit(c)){
                    number();
                } else if (isAlpha(c)){
                    identifier();
                } else {
                    Lox.error(line, "Unexpected character.");
                }
                break;

        }
        
    }
    //Método que identifica o próximo token baseado no caractere atual e adiciona esse token à lista tokens.

    private static final Map<String, TokenType> keywords;

    //Define um mapeamento de palavras-chave da linguagem para seus respectivos tipos de token.
    static {
        keywords = new HashMap<>();
        keywords.put("and",    AND);
        keywords.put("class",  CLASS);
        keywords.put("else",   ELSE);
        keywords.put("false",  FALSE);
        keywords.put("for",    FOR);
        keywords.put("fun",    FUN);
        keywords.put("if",     IF);
        keywords.put("nil",    NIL);
        keywords.put("or",     OR);
        keywords.put("print",  PRINT);
        keywords.put("return", RETURN);
        keywords.put("super",  SUPER);
        keywords.put("this",   THIS);
        keywords.put("true",   TRUE);
        keywords.put("var",    VAR);
        keywords.put("while",  WHILE);
    }

    //Bloco estático para inicializar o mapeamento de palavras-chave.



    // meotodo para comentarios de bloco
    private void blockComment() {
        int commentNesting = 1;
        while (commentNesting > 0 && !isAtEnd()) {
            if (peek() == '*' && peekNext() == '/') {
                // Found the end of a block comment.
                advance(); // Consume '*'
                advance(); // Consume '/'
                commentNesting--;
            } else if (peek() == '/' && peekNext() == '*') {
                // Found the start of a nested block comment.
                advance(); // Consume '/'
                advance(); // Consume '*'
                commentNesting++;
            } else {
                if (peek() == '\n') line++;
                advance();
            }
        }

        if (isAtEnd() && commentNesting > 0) {
            Lox.error(line, "Unterminated block comment.");
        }
    }


    private void string(){
        while (peek() != '"' && !isAtEnd()){
            if (peek() == '\n') line++;
            advance();
        }
        if (isAtEnd()){
            Lox.error(line, "Unterminated string.");
            return;
        }
        advance();
        String value = source.substring(start + 1, current - 1);
        addToken(STRING, value);
    }

    //O método advance() consome o próximo caractere no arquivo de origem e o retorna.
    //Onde advance() é para entrada, addToken() é para saída.
    //Ele pega o texto do lexema atual e cria um novo token para ele.
    //Usaremos a outra sobrecarga para lidar com tokens com valores literais em breve.


//Método para identificar e adicionar tokens de strings literais.
    private char peek(){
        if (isAtEnd()) return '\0';
        return source.charAt(current);
    }
    //Método que retorna o caractere atual sem consumi-lo.
    private boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    //Método auxiliar para verificar se um caractere é um dígito.
    private void number() {
        while (isDigit(peek())) advance();

        // Look for a fractional part.
        if (peek() == '.' && isDigit(peekNext())) {
            // Consume the "."
            advance();

            while (isDigit(peek())) advance();
        }

        addToken(NUMBER,
                Double.parseDouble(source.substring(start, current)));
    }
//Método para identificar e adicionar tokens numéricos, incluindo partes fracionárias.
    private char peekNext() {
        if (current + 1 >= source.length()) return '\0';
        return source.charAt(current + 1);
    }

    private void identifier() {
        while (isAlphaNumeric(peek())) advance();
      //modifictions
        String text = source.substring(start, current);
        TokenType type = keywords.get(text);
        if (type == null) type = IDENTIFIER;
        addToken(type);

       // addToken(IDENTIFIER);
    }

    private boolean isAlpha(char c) {
        return (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                c == '_';
    }

    private boolean isAlphaNumeric(char c) {
        return isAlpha(c) || isDigit(c);
    }

//Método auxiliar para verificar se um caractere é alfanumérico.
    private boolean match(char expected){
        if (isAtEnd()) return false;
        if (source.charAt(current) != expected) return false;

        current++;
        return true;
    }
//Método que consome o próximo caractere se ele corresponder ao caractere esperado.
    private char advance(){
        return source.charAt(current++);
    }
    //Método que consome e retorna o próximo caractere do código fonte.
    private void addToken(TokenType type){
        addToken(type, null);
    }

    private void addToken(TokenType type, Object literal){
        String text = source.substring(start, current);
        tokens.add(new Token(type, text, literal, line));
    }

    //    source: o código fonte a ser analisado.
    //    tokens: uma lista para armazenar os tokens identificados.
    //    start: índice do início do token atual no source.
    //    current: índice do caractere atual sendo analisado no source.
    //    line: mantém o controle do número da linha atual, útil para relatar erros.

//Cada parte desse código trabalha em conjunto para desmembrar o código fonte em tokens,
// que são então usados por outras partes de um interpretador ou compilador para análise sintática e
// semântica.


}
