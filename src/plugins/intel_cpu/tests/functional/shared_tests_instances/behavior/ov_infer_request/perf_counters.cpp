// Copyright (C) 2018-2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "behavior/ov_infer_request/perf_counters.hpp"

using namespace ov::test::behavior;

namespace {
const std::vector<ov::AnyMap> configs = {
        {},
        // Test with single thread - streams should be auto-calculated
        {{ov::inference_num_threads(1)}, {ov::enable_profiling(true)}},
        // Test with explicit single stream
        {{ov::num_streams(1)}, {ov::inference_num_threads(1)}, {ov::enable_profiling(true)}}
};

INSTANTIATE_TEST_SUITE_P(smoke_BehaviorTests, OVInferRequestPerfCountersTest,
                        ::testing::Combine(
                                ::testing::Values(ov::test::utils::DEVICE_CPU),
                                ::testing::ValuesIn(configs)),
                         OVInferRequestPerfCountersTest::getTestCaseName);
}  // namespace
