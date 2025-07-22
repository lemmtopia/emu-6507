    processor 6502
    
    seg code
    org $F000

Start:
    nop

    org $FFFC
    .word Start
    .word Start
