/*=========================================================================

  Program:   Diffusion Applications
  Module:    $HeadURL: http://svn.slicer.org/Slicer4/trunk/Modules/CLI/ResampleDTIVolume/itkDiffusionTensor3DWindowedSincInterpolateImageFunction.h $
  Language:  C++
  Date:      $Date: 2013-01-11 16:30:04 -0500 (Fri, 11 Jan 2013) $
  Version:   $Revision: 21594 $

  Copyright (c) Brigham and Women's Hospital (BWH) All Rights Reserved.

  See License.txt or http://www.slicer.org/copyright/copyright.txt for details.

==========================================================================*/
#ifndef __itkDiffusionTensor3DWindowedSincInterpolateImageFunction_h
#define __itkDiffusionTensor3DWindowedSincInterpolateImageFunction_h

#include "itkDiffusionTensor3DInterpolateImageFunctionReimplementation.h"
#include <itkWindowedSincInterpolateImageFunction.h>
#include <itkConstantBoundaryCondition.h>
#include <itkImage.h>

namespace itk
{
/**
 * \class DiffusionTensor3DWindowedSincInterpolateImageFunction
 *
 * Implementation of windowed sinc blockwise interpolation for diffusion tensor images
 */
template <class TData,
          unsigned int VRadius,
          class TWindowFunction = Function::HammingWindowFunction<VRadius>,
          class TBoundaryCondition = ConstantBoundaryCondition<Image<TData, 3> >,
          class TCoordRep = double
          >
class DiffusionTensor3DWindowedSincInterpolateImageFunction
  : public DiffusionTensor3DInterpolateImageFunctionReimplementation<TData, TCoordRep>
{
public:
  typedef TData                                                                          DataType;
  typedef DiffusionTensor3DWindowedSincInterpolateImageFunction                          Self;
  typedef DiffusionTensor3DInterpolateImageFunctionReimplementation<DataType, TCoordRep> Superclass;
  typedef typename Superclass::ImageType                                                 ImageType;
  typedef SmartPointer<Self>                                                             Pointer;
  typedef SmartPointer<const Self>                                                       ConstPointer;
  typedef WindowedSincInterpolateImageFunction<ImageType,
                                               VRadius, TWindowFunction,
                                               TBoundaryCondition, TCoordRep> WindowedSincInterpolateImageFunctionType;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DiffusionTensor3DWindowedSincInterpolateImageFunction, DiffusionTensor3DInterpolateImageFunctionReimplementation);

  itkNewMacro(Self);
protected:
  void AllocateInterpolator();

  typename WindowedSincInterpolateImageFunctionType::Pointer windowedSincInterpolator[6];
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkDiffusionTensor3DWindowedSincInterpolateImageFunction.txx"
#endif

#endif
