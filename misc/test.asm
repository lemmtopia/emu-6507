    processor 6502
    
    seg code
    org $F000

Start:
    lda #$69

    org $FFFC
    .word Start
    .word Start
