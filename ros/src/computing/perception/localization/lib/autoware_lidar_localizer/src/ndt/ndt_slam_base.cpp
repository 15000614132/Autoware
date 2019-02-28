/*
 * Copyright 2015-2019 Autoware Foundation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "lidar_localizer/ndt/ndt_slam_base.h"

template <class PointSource, class PointTarget>
NdtSlamBase<PointSource, PointTarget>::NdtSlamBase()
{
}

template <class PointSource, class PointTarget>
std::stringstream NdtSlamBase<PointSource, PointTarget>::logFileContent() const
{
    std::stringstream content = LidarLocalizer<PointSource, PointTarget>::logFileContent();
    content << ","
            << getTransformationProbability();
    return content;
}

template class NdtSlamBase<pcl::PointXYZ, pcl::PointXYZ>;
template class NdtSlamBase<pcl::PointXYZI, pcl::PointXYZI>;