package Pieces;

import Board.Board;

public class Bishop extends pieces {
    int x = -1;
    int y = -1;

    public Bishop(boolean isWhite) {
        super(isWhite);
    }

    public Bishop(boolean isWhite, int x, int y) {
        super(isWhite);
        this.x = x;
        this.y = y;
    }

    public String getImage() {
        if (isWhite()) {
            return "/ChessPiecesImages/WhiteBishop.png";
        }
        return "/ChessPiecesImages/BlackBishop.png";
    }

    public boolean canMove(Board board, Position start, Position end) {
        char[][] boardArray = board.getBoard();

        int startX = start.getRow();
        int startY = start.getCol();
        int endX = end.getRow();
        int endY = end.getCol();

        char startPiece = boardArray[startX][startY];
        char endPiece = boardArray[endX][endY];

        if (isWhite() && boardArray[endX][endY] >= 65 && boardArray[endX][endY] <= 90) {
            return false;
        }
        if (!isWhite() && boardArray[endX][endY] >= 97 && boardArray[endX][endY] <= 122) {
            return false;
        }

        if (endPiece != '-' && startPiece == endPiece) {
            return false;
        }

        // Checks if diagonal
        int xDiff = Math.abs(startX - endX);
        int yDiff = Math.abs(startY - endY);

        if (xDiff != yDiff) {
            return false;
        }

        return isPathClear(boardArray, start, end);
    }

    public boolean isValidMove(Board board, Position start, Position end) {
        return canMove(board, start, end);
    }

    private boolean isPathClear(char[][] board, Position start, Position end) {
        int startX = start.getRow();
        int startY = start.getCol();
        int endX = end.getRow();
        int endY = end.getCol();

        int xDirection = (endX > startX) ? 1 : -1;
        int yDirection = (endY > startY) ? 1 : -1;

        int x = startX + xDirection;
        int y = startY + yDirection;

        while (x != endX && y != endY) {
            if (x < 0 || x >= 8 || y < 0 || y >= 8) {
                return false;
            }
            if (board[x][y] != '-') {
                return false;
            }
            x += xDirection;
            y += yDirection;
        }

        return true;
    }

    public int getValue() {
        return 3;
    }
}
