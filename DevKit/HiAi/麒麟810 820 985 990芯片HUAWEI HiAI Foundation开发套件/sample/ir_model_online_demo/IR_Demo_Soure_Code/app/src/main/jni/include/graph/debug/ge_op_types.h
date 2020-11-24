/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the Apache License Version 2.0.You may not use this file except in compliance with the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Apache License for more details at
 * http: // www.apache.org/licenses/LICENSE-2.0
 */

#ifndef GE_OP_TYPES_H_
#define GE_OP_TYPES_H_

#include <stdint.h>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <climits>
#ifndef _MSC_VER
#include <linux/limits.h>
#else
#include "common_win.h"
#endif

namespace ge {
#define GE_REGISTER_OPTYPE(varName, strName) static const char* varName __attribute__((unused)) = strName;

GE_REGISTER_OPTYPE(DATA, "Data");
GE_REGISTER_OPTYPE(CONVOLUTION, "Convolution");
GE_REGISTER_OPTYPE(CORRELATION, "Correlation");
GE_REGISTER_OPTYPE(CORRELATIONV2, "Correlation_V2");
GE_REGISTER_OPTYPE(DECONVOLUTION, "ConvTranspose");
GE_REGISTER_OPTYPE(POOLING, "PoolingD");
GE_REGISTER_OPTYPE(ELTWISE, "Eltwise");
GE_REGISTER_OPTYPE(RELU, "ReLU");
GE_REGISTER_OPTYPE(RELU6, "ReLU6");
GE_REGISTER_OPTYPE(SIGMOID, "Sigmoid");
GE_REGISTER_OPTYPE(ABSVAL, "AbsVal");
GE_REGISTER_OPTYPE(TANH, "TanH");
GE_REGISTER_OPTYPE(PRELU, "PReLU");
GE_REGISTER_OPTYPE(BATCHNORM, "BNInference");
GE_REGISTER_OPTYPE(FUSIONBATCHNORM, "FusionBatchNorm");
GE_REGISTER_OPTYPE(SCALE, "Scale");
GE_REGISTER_OPTYPE(FULL_CONNECTION, "FullyConnection");
GE_REGISTER_OPTYPE(SOFTMAX, "Softmax");
GE_REGISTER_OPTYPE(PLUS, "Plus");
GE_REGISTER_OPTYPE(ACTIVATION, "Activation");
GE_REGISTER_OPTYPE(HARDSWISH, "HardSwish");
GE_REGISTER_OPTYPE(FLATTEN, "Flatten");
GE_REGISTER_OPTYPE(ADD, "Add");
GE_REGISTER_OPTYPE(SUB, "Sub");
GE_REGISTER_OPTYPE(MUL, "Mul");
GE_REGISTER_OPTYPE(MATMUL, "MatMul");
GE_REGISTER_OPTYPE(RSQRT, "Rsqrt");
GE_REGISTER_OPTYPE(BIASADD, "BiasAdd");
GE_REGISTER_OPTYPE(RESHAPE, "Reshape");
GE_REGISTER_OPTYPE(DEPCONVOLUTION, "ConvolutionDepthwise");
GE_REGISTER_OPTYPE(DROPOUT, "Dropout");
GE_REGISTER_OPTYPE(CONCAT, "ConcatD");
GE_REGISTER_OPTYPE(ROIPOOLING, "ROIPooling");
GE_REGISTER_OPTYPE(PROPOSAL, "Proposal");
GE_REGISTER_OPTYPE(FSRDETECTIONOUTPUT, "FSRDetectionOutput");
GE_REGISTER_OPTYPE(DETECTIONPOSTPROCESS, "Detectpostprocess");
GE_REGISTER_OPTYPE(LRN, "LRN");
GE_REGISTER_OPTYPE(TRANSDATA, "TransData");
GE_REGISTER_OPTYPE(PERMUTE, "Permute");
GE_REGISTER_OPTYPE(SSDNORMALIZE, "SSDNormalize");
GE_REGISTER_OPTYPE(SSDPRIORBOX, "SSDPriorBox");
GE_REGISTER_OPTYPE(NETOUTPUT, "NetOutput");
GE_REGISTER_OPTYPE(SSDDETECTIONOUTPUT, "SSDDetectionOutput");
GE_REGISTER_OPTYPE(CHANNELAXPY, "ChannelAxpy");
GE_REGISTER_OPTYPE(PSROIPOOLING, "PSROIPooling");
GE_REGISTER_OPTYPE(POWER, "Power");
GE_REGISTER_OPTYPE(ROIALIGN, "ROIAlign");
GE_REGISTER_OPTYPE(PYTHON, "Python");
GE_REGISTER_OPTYPE(FREESPACEEXTRACT, "FreespaceExtract");
GE_REGISTER_OPTYPE(SPATIALTF, "SpatialTransform");
GE_REGISTER_OPTYPE(SHAPE, "Shape");
GE_REGISTER_OPTYPE(ARGMAX, "ArgMaxExt2");
GE_REGISTER_OPTYPE(GATHERND, "GatherNd");
GE_REGISTER_OPTYPE(GATHER, "GatherV2D");
GE_REGISTER_OPTYPE(REALDIV, "RealDiv");
GE_REGISTER_OPTYPE(PACK, "Pack");
GE_REGISTER_OPTYPE(SLICE, "Slice");
GE_REGISTER_OPTYPE(FLOORDIV, "FloorDiv");
GE_REGISTER_OPTYPE(SQUEEZE, "Squeeze");
GE_REGISTER_OPTYPE(STRIDEDSLICE, "StridedSlice");
GE_REGISTER_OPTYPE(RANGE, "Range");
GE_REGISTER_OPTYPE(RPNPROPOSALS, "GenerateRpnProposals");
GE_REGISTER_OPTYPE(DECODEBBOX, "DecodeBBox");
GE_REGISTER_OPTYPE(PAD, "Pad");
GE_REGISTER_OPTYPE(TILE, "Tile");
GE_REGISTER_OPTYPE(SIZE, "Size");
GE_REGISTER_OPTYPE(CLIPBOXES, "Clipboxes");
GE_REGISTER_OPTYPE(FASTRCNNPREDICTIONS, "FastrcnnPredictions");
GE_REGISTER_OPTYPE(SPLIT, "SplitD");
GE_REGISTER_OPTYPE(STOPGRADIENT, "StopGradient");
GE_REGISTER_OPTYPE(LAYERNORM, "LayerNorm");
GE_REGISTER_OPTYPE(INSTANCENORM, "InstanceNorm");
GE_REGISTER_OPTYPE(EXPANDDIMS, "ExpandDims");
GE_REGISTER_OPTYPE(MEAN, "Mean");
GE_REGISTER_OPTYPE(GREATER, "Greater");
GE_REGISTER_OPTYPE(SWITCH, "Switch");
GE_REGISTER_OPTYPE(MERGE, "Merge");
GE_REGISTER_OPTYPE(TRANSPOSE, "Transpose");
GE_REGISTER_OPTYPE(CAST, "CastT");
GE_REGISTER_OPTYPE(REGION, "Region")
GE_REGISTER_OPTYPE(YOLO, "Yolo")
GE_REGISTER_OPTYPE(YOLODETECTIONOUTPUT, "YoloDetectionOutput")
GE_REGISTER_OPTYPE(FILL, "Fill");
GE_REGISTER_OPTYPE(REVERSE, "Reverse");
GE_REGISTER_OPTYPE(UNPACK, "Unpack");
GE_REGISTER_OPTYPE(YOLO2REORG, "Yolo2Reorg");
GE_REGISTER_OPTYPE(REDUCESUM, "ReduceSum");
GE_REGISTER_OPTYPE(CONSTANT, "Const");
GE_REGISTER_OPTYPE(RESIZEBILINEAR, "ResizeBilinear");
GE_REGISTER_OPTYPE(MAXIMUM, "Maximum");
GE_REGISTER_OPTYPE(FRAMEWORKOP, "FrameworkOp");
GE_REGISTER_OPTYPE(ARG, "_Arg");
GE_REGISTER_OPTYPE(FUSEDBATCHNORMGRAD, "FusedBatchNormGrad");
GE_REGISTER_OPTYPE(LSTM, "LSTM");
GE_REGISTER_OPTYPE(HIGHWAY, "HighWay");
GE_REGISTER_OPTYPE(RNN, "RNN");
GE_REGISTER_OPTYPE(ATTENTIONDECODER, "AttentionDecoder");
GE_REGISTER_OPTYPE(LOGICAL_NOT, "LogicalNot");
GE_REGISTER_OPTYPE(LOGICAL_AND, "LogicalAnd");
GE_REGISTER_OPTYPE(EQUAL, "Equal");
GE_REGISTER_OPTYPE(INTERP, "Interp");
GE_REGISTER_OPTYPE(SHUFFLECHANNEL, "ShuffleChannel");
GE_REGISTER_OPTYPE(AIPP, "Aipp");
GE_REGISTER_OPTYPE(AIPP_CONFIG_OP, "AippConfig");

GE_REGISTER_OPTYPE(CLIPBYVALUE, "ClipByValue");
GE_REGISTER_OPTYPE(ARGMIN, "ArgMin");
GE_REGISTER_OPTYPE(BATCHMATMUL, "BatchMatMul");
GE_REGISTER_OPTYPE(CROPANDRESIZE, "CropAndResize");
GE_REGISTER_OPTYPE(UNUSEDCONST, "UnusedConst");
GE_REGISTER_OPTYPE(SPARSETODENSE, "SparseToDense");
GE_REGISTER_OPTYPE(NONMAXSUPPRESSION, "NonMaxSuppressionV3D");
GE_REGISTER_OPTYPE(TOPKV2, "TopK");
GE_REGISTER_OPTYPE(INVERTPERMUTATION, "InvertPermutation");
GE_REGISTER_OPTYPE(MULTINOMIAL, "Multinomial");
GE_REGISTER_OPTYPE(REVERSESEQUENCE, "ReverseSequence");
GE_REGISTER_OPTYPE(COPY, "Copy");
GE_REGISTER_OPTYPE(BATCHREINDEX, "BatchReindex");
GE_REGISTER_OPTYPE(REDUCEMEAN, "ReduceMean");
GE_REGISTER_OPTYPE(CROP, "Crop");
GE_REGISTER_OPTYPE(EXPM1, "Expm1");
GE_REGISTER_OPTYPE(CEIL, "Ceil");
GE_REGISTER_OPTYPE(SIN, "Sin");
GE_REGISTER_OPTYPE(COS, "Cos");
GE_REGISTER_OPTYPE(FLOOR, "Floor");
GE_REGISTER_OPTYPE(LOG1P, "Log1p");
GE_REGISTER_OPTYPE(LOGICALAND, "LogicalAnd");
GE_REGISTER_OPTYPE(LOGICALNOT, "LogicalNot");
GE_REGISTER_OPTYPE(MINIMUM, "Minimum");
GE_REGISTER_OPTYPE(ACOSH, "Acosh");
GE_REGISTER_OPTYPE(ASINH, "Asinh");
GE_REGISTER_OPTYPE(RECIPROCAL, "Reciprocal");
GE_REGISTER_OPTYPE(SQRT, "Sqrt");
GE_REGISTER_OPTYPE(SIGN, "Sign");
GE_REGISTER_OPTYPE(COSH, "Cosh");
GE_REGISTER_OPTYPE(EXP, "Exp");
GE_REGISTER_OPTYPE(FLOORMOD, "FloorMod");
GE_REGISTER_OPTYPE(GREATEREQUAL, "GreaterEqual");
GE_REGISTER_OPTYPE(LESS, "Less");
GE_REGISTER_OPTYPE(RINT, "Rint");
GE_REGISTER_OPTYPE(ROUND, "Round");
GE_REGISTER_OPTYPE(SINH, "Sinh");
GE_REGISTER_OPTYPE(ACOS, "Acos");
GE_REGISTER_OPTYPE(ASIN, "Asin");
GE_REGISTER_OPTYPE(ATANH, "Atanh");
GE_REGISTER_OPTYPE(LOG, "Log");
GE_REGISTER_OPTYPE(LOGICALOR, "LogicalOr");
GE_REGISTER_OPTYPE(NEG, "Neg");
GE_REGISTER_OPTYPE(TAN, "Tan");
GE_REGISTER_OPTYPE(NOTEQUAL, "NotEqual");
GE_REGISTER_OPTYPE(LESSEQUAL, "LessEqual");
GE_REGISTER_OPTYPE(TRUNCATEMOD, "TruncateMod");
GE_REGISTER_OPTYPE(POW, "Pow");
GE_REGISTER_OPTYPE(SQUAREDDIFFERENCE, "SquaredDifference");
GE_REGISTER_OPTYPE(ATAN, "Atan");
GE_REGISTER_OPTYPE(LOGICALXOR, "LogicalXor");
GE_REGISTER_OPTYPE(BNLL, "BNLL");
GE_REGISTER_OPTYPE(SWISH, "Swish");
GE_REGISTER_OPTYPE(AXIS_ALIGNED_BBOX_TRANSFORM, "AxisAlignedBboxTransform");
GE_REGISTER_OPTYPE(SELECT, "Select");
GE_REGISTER_OPTYPE(UNSORTEDSEGMENTSUM, "UnsortedSegmentSum");
GE_REGISTER_OPTYPE(CUMSUM, "Cumsum");
GE_REGISTER_OPTYPE(CUMPROD, "Cumprod");
GE_REGISTER_OPTYPE(REDUCEANY, "ReduceAny");
GE_REGISTER_OPTYPE(SEGMENTMAX, "SegmentMax");
GE_REGISTER_OPTYPE(SEGMENTMIN, "SegmentMin");
GE_REGISTER_OPTYPE(SEGMENTMEAN, "SegmentMean");
GE_REGISTER_OPTYPE(SEGMENTSUM, "SegmentSum");
GE_REGISTER_OPTYPE(SEGMENTPROD, "SegmentProd");
GE_REGISTER_OPTYPE(THRESHOLD, "Threshold");
GE_REGISTER_OPTYPE(SPACETOBATCHND, "SpaceToBatchND");
GE_REGISTER_OPTYPE(BATCHTOSPACEND, "BatchToSpaceND");
GE_REGISTER_OPTYPE(PADV2, "PadV2");
GE_REGISTER_OPTYPE(SPACETODEPTH, "SpaceToDepth");
GE_REGISTER_OPTYPE(RANDOMUNIFORMNOSEED, "RandomUniformNoSeed");
GE_REGISTER_OPTYPE(LOGSOFTMAX, "LogSoftmax");
GE_REGISTER_OPTYPE(QUANTIZEDFULL_CONNECTION, "QuantizedFullyConnection");
GE_REGISTER_OPTYPE(QUANTIZEDDEPCONVOLUTION, "QuantizedConvolutionDepthwise");
GE_REGISTER_OPTYPE(RESIZENEARESTNEIGHBOR, "ResizeNearestNeighbor");
GE_REGISTER_OPTYPE(HEATMAPMAXKEYPOINT, "HeatmapMaxKeypoint");
GE_REGISTER_OPTYPE(REDUCEALLD, "ReduceAllD");
GE_REGISTER_OPTYPE(REDUCEPRODD, "ReduceProdD");
GE_REGISTER_OPTYPE(RANK, "Rank");
GE_REGISTER_OPTYPE(DEQUANTIZE, "Dequantize");
GE_REGISTER_OPTYPE(QUANTIZE, "Quantize");
GE_REGISTER_OPTYPE(SPLITV, "SplitV");
GE_REGISTER_OPTYPE(DEPTHTOSPACE, "DepthToSpace");
GE_REGISTER_OPTYPE(EXTRACTIMAGEPATCHES, "ExtractImagePatches");
GE_REGISTER_OPTYPE(SCATTERND, "ScatterNd");
GE_REGISTER_OPTYPE(FAKEQUANTWITHMINMAXVARSPERCHANNEL, "FakeQuantWithMinMaxVarsPerChannel");
GE_REGISTER_OPTYPE(ONEHOT, "OneHot");
GE_REGISTER_OPTYPE(DETECTIONOSTPROCESSING, "DetectionPostprocessing");
GE_REGISTER_OPTYPE(ERF, "Erf");
GE_REGISTER_OPTYPE(MIRRORPAD, "MirrorPad");
GE_REGISTER_OPTYPE(REDUCEMAX, "ReduceMax");
GE_REGISTER_OPTYPE(REDUCEMIN, "ReduceMin");
GE_REGISTER_OPTYPE(L2NORMALIZE, "L2Normalize");
GE_REGISTER_OPTYPE(SSDPOSTPROCESSOR, "SSDPostProcessor");
GE_REGISTER_OPTYPE(UPSAMPLE, "Upsample");
GE_REGISTER_OPTYPE(CHANNELSHUFFLE, "ShuffleChannelV2");
GE_REGISTER_OPTYPE(NORMALIZE, "Normalize");
GE_REGISTER_OPTYPE(SPP, "SPP");
GE_REGISTER_OPTYPE(BIAS, "Bias");
GE_REGISTER_OPTYPE(RANDOMSHUFFLE, "RandomShuffleNoSeed");
GE_REGISTER_OPTYPE(RANDOMNORMAL, "RandomNormalNoSeed");
GE_REGISTER_OPTYPE(RANDOMUNIFORMINT, "RandomUniformInt");
GE_REGISTER_OPTYPE(SVDF, "SVDF");
GE_REGISTER_OPTYPE(FAKEQUANTWITHMINMAXVARS, "FakeQuantWithMinMaxVars");
GE_REGISTER_OPTYPE(FRACTIONALPOOLING, "FractionalPooling");
/* **************ANN专用算子************************ */
GE_REGISTER_OPTYPE(ANN_MEAN, "AnnMean");
GE_REGISTER_OPTYPE(ANN_CONVOLUTION, "AnnConvolution");
GE_REGISTER_OPTYPE(ANN_DEPCONVOLUTION, "AnnDepthConv");
GE_REGISTER_OPTYPE(DIV, "Div");
GE_REGISTER_OPTYPE(ANN_FULLCONNECTION, "AnnFullConnection");
GE_REGISTER_OPTYPE(ANN_NETOUTPUT, "AnnNetOutput");
GE_REGISTER_OPTYPE(ANN_DATA, "AnnData");
/***************************************************/
/* *****************训练算子************************ */
GE_REGISTER_OPTYPE(CONVGRADFILTER, "Conv2DBackpropFilter");
GE_REGISTER_OPTYPE(CONV2D, "Conv2D");
GE_REGISTER_OPTYPE(CONV2DBACKPROPINPUT, "Conv2DBackpropInput");
GE_REGISTER_OPTYPE(ACTIVATIONGRAD, "ReluGrad");
/***************************************************/
GE_REGISTER_OPTYPE(SQUARE, "Square");

/*
 * @ingroup domi_omg
 * @brief INPUT节点类型
 */
const char* const INPUT_TYPE = "Input";

/*
 * @ingroup domi_omg
 * @brief DATA节点类型
 */
const char* const DATA_TYPE = "Data";
const char* const IMAGE_DATA_TYPE = "ImageData";
const char* const DYNAMIC_IMAGE_DATA_TYPE = "DynamicImageData";
const char* const AIPP_CONFIG = "AippConfig";

/*
 * @ingroup domi_omg
 * @brief 框架算子类型
 */
const char* const FRAMEWORK_OP_TYPE = "FrameworkOp";

/*
 * @ingroup domi_omg
 * @brief DATA节点类型
 */
const char* const ANN_DATA_TYPE = "AnnData";
const char* const ANN_NETOUTPUT_TYPE = "AnnNetOutput";
/*
 * @ingroup domi_omg
 * @brief 卷积节点类型
 */
const char* const NODE_NAME_NET_OUTPUT = "Node_Output";

/*
 * @ingroup domi_omg
 * @brief 卷积节点类型
 */
const char* const OP_TYPE_CONVOLUTION = "Convolution";
/*
 * @ingroup domi_omg
 * @brief 为硬AIPP增加卷积节点名字
 */
const char* const AIPP_CONV_OP_NAME = "aipp_conv_op";

/*
 * @ingroup domi_omg
 * @brief 带aipp场景下,data原始维度
 */
const char* const AIPP_MODEL_DATA_DIM_W = "aipp_model_data_dim_w";
const char* const AIPP_MODEL_DATA_DIM_H = "aipp_model_data_dim_h";
const char* const AIPP_MODEL_DATA_DIM_C = "aipp_model_data_dim_c";
const char* const AIPP_MODEL_DATA_TYPE = "aipp_model_data_type";

/*
 * @ingroup domi_omg
 * @brief 算子配置项分隔符
 */
const char* const OP_CONF_DELIMITER = ":";
}; // namespace ge

#endif // GE_OP_TYPES_H_
