/* weights_meta.h – description of read-only blobs generated by
 *                  utils/export_weights.py
 * ------------------------------------------------------------------ */
#ifndef WEIGHTS_META_H
#define WEIGHTS_META_H
#pragma once

#include <stdint.h>

/* ------------------------------------------------------------------ */
/* A single record for one data blob                                   */
typedef enum { WT_QINT8 = 0,    /* int8 payload  */
               WT_FLOAT32 = 1   /* float32 payload*/ } WT_Type;

typedef struct {
    const void *ptr;        /* pointer into weights.c               */
    uint32_t    size;       /* number of elements (not bytes)       */
    uint8_t     type;       /* WT_QINT8 or WT_FLOAT32               */
    uint8_t     dims;       /* 1–4                                  */
    uint8_t     shape[4];   /* padded to 4-D                        */
    const char *name;       /* original PyTorch param name          */
} WT_Entry;

/* ------------------------------------------------------------------ */
/* Exported by weights_meta.c (auto-generated)                         */
extern const WT_Entry  g_wt_table[];
extern const uint32_t  g_wt_count;

/* Simple helper implemented in utils.c – returns NULL if not found.   */
const WT_Entry *find_named_entry(const char *tag);

#endif /* WEIGHTS_META_H */
