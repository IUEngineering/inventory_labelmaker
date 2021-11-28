// Code made by Datalogger Illya
// For CM Inventry Managmenet wtih LABLES
// Based on PDFgen library:
// https://github.com/AndreRenaud/PDFGen

#include <stdio.h>
#include "lib/pdfgen.h"
#include <string.h>

#define LABEL_LARGE_WIDTH PDF_MM_TO_POINT(101.0f)
#define LABEL_LARGE_HEIGHT PDF_MM_TO_POINT(54.0f)



#define BARCODE_X 20
#define BARCODE_MANF_Y 90
#define BARCODE_INTERN_Y 50

#define BARCODE_TEXT1 "RC0805-asdasdasd"
#define BARCODE_TEXT2 "Hi Tycho"

int main() {
    struct pdf_info info = {
            .creator = "CM PDF Creator for Lables",
            .producer = "My software",
            .title = "My document",
            .author = "Illya - Datalogger",
            .subject = "My subject",
            .date = "Today"
    };

    char manufacturer[] = "Manuf #: ";

    struct pdf_doc *pdf = pdf_create(LABEL_LARGE_WIDTH, LABEL_LARGE_HEIGHT, &info);
    pdf_set_font(pdf, "Times-Roman");
    pdf_append_page(pdf);
//    pdf_add_text(pdf, NULL, "Capacitor 20 uF - Package: 0805", 20, 20, 130, PDF_BLACK);
//    pdf_add_line(pdf, NULL, 0, 120, 500, 120, 3, PDF_BLACK);
//
//    //Manufacturer Barcode + text
//    pdf_add_barcode(pdf, NULL, PDF_BARCODE_128A, BARCODE_X , BARCODE_MANF_Y, 250, 25, BARCODE_TEXT1, 000000);
//    pdf_add_text(pdf, NULL, BARCODE_TEXT1, 10, BARCODE_X, BARCODE_MANF_Y-10, PDF_BLACK);
//
//    // Intern Barcode + text
//
//    pdf_add_barcode(pdf, NULL, PDF_BARCODE_128A, BARCODE_X , BARCODE_INTERN_Y , 250, 25, BARCODE_TEXT2, 000000);
//    pdf_add_text(pdf, NULL, strcat(manufacturer, BARCODE_TEXT2), 10, BARCODE_X, BARCODE_INTERN_Y -10, PDF_BLACK);

    pdf_add_text(pdf, NULL, "D2 - PROTECTOR FAULT", 20, 20, 130, PDF_BLACK);
    pdf_add_text(pdf, NULL, "D6 - PRECHARGE DONE", 20, 20, 115, PDF_BLACK);
    pdf_add_text(pdf, NULL, "D10 - 'PHASE U' ", 20, 20, 100, PDF_BLACK);
    pdf_add_text(pdf, NULL, "D14 - 'PHASE U' ", 20, 20, 85, PDF_BLACK);
    pdf_add_text(pdf, NULL, "D17 - 'PHASE U' ", 20, 20, 70, PDF_BLACK);
    pdf_add_text(pdf, NULL, "D20 - 'PHASE U'", 20, 20, 55, PDF_BLACK);



    pdf_save(pdf, "output.pdf");
    pdf_destroy(pdf);
    return 0;
}
