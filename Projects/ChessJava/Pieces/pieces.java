package Pieces;

import Board.Board;

public abstract class pieces {
    private boolean taken = false;
    private boolean white;

    public pieces(boolean white) {
        this.white = white;
    }

    public boolean isWhite() {
        return this.white;
    }

    public void setWhite(boolean white) {
        this.white = white;
    }

    public boolean isTaken() {
        return this.taken;
    }

    public void setTaken(boolean taken) {
        this.taken = taken;
    }

    public static pieces getPiece(char piece) {
        boolean isWhite = Character.isUpperCase(piece);
        piece = Character.toUpperCase(piece);

        switch (piece) {
            case 'P':
                return new Pawn(isWhite);
            case 'R':
                return new Rook(isWhite);
            case 'N':
                return new Knight(isWhite);
            case 'B':
                return new Bishop(isWhite);
            case 'Q':
                return new Queen(isWhite);
            case 'K':
                return new King(isWhite);
            default:
                return null;
        }
    }

    public abstract int getValue();

    public abstract boolean canMove(Board board, Position start, Position end);

    public abstract String getImage();
}
